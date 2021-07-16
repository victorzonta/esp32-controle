#include <Arduino.h>
#include "BluetoothSerial.h"

#define btn1 23
#define btn2 22
#define btn3 21
#define btn4 19
#define btn5 18

BluetoothSerial SerialBT;

String MACadd = "98:D3:61:F5:C8:69";//mudar 
uint8_t address[6]  = {0x98, 0xD3, 0x61, 0xF5, 0xC8, 0x69};// mudar
String name = "HC-05";//mudar
char *pin = "1234"; //<- standard pin would be provided by default //mudar
bool connected;
bool aceso = false; //true

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  
  Serial.begin(9600);
  SerialBT.begin("ESP32test", true); 
  SerialBT.setPin(pin);
  Serial.println("The device started in master mode, make sure remote BT device is on!"); 
  
  connected = SerialBT.connect(address);
  
  if(connected) {
    Serial.println("Connected Succesfully!");
    
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  // this would reconnect to the name(will use address, if resolved) or address used with connect(name/address).
  SerialBT.connect();
}

void loop() {
  if (digitalRead (btn1) == LOW )
{
    SerialBT.print("F");// A condição é verdadeira, faça algo..
    delay(100);
    SerialBT.print("S");
}

if (digitalRead (btn2) == LOW )
{
    SerialBT.print("B");// A condição é verdadeira, faça algo..
    delay(100);
    SerialBT.print("S");
}
if (digitalRead (btn3) == LOW )
{
    SerialBT.print("R");// A condição é verdadeira, faça algo..
    delay(100);
    SerialBT.print("S");
}
if (digitalRead (btn4) == LOW )
{
    SerialBT.print("L");// A condição é verdadeira, faça algo..
    delay(100);
    SerialBT.print("S");
}

 if(digitalRead(btn5) == LOW){
    delay(300);
    if (aceso)
     (SerialBT.print("w"));
    else  
     (SerialBT.print("W")); 
  // digitalWrite(SerialBT.print("W"), !digitalRead(SerialBT.print("w")));
aceso=!aceso; //a variavel recebe o proprio valor ao contrario
}
//ternario
// if(digitalRead(btn5) == LOW){
//     delay(300);
//     if (aceso){
//      (SerialBT.print("w"));
//      aceso = false;
//    }
//     else{
//      (SerialBT.print("W"));
//      aceso = true;
//  }
// }
         
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
}