#include <SoftwareSerial.h>
#define LED_PIN 13

//Testing

SoftwareSerial BT05(10, 11); //RX|TX

// Connect BT05      Arduino Uno
//     RXD            Pin 10
//     TXD            Pin 11

void setup() {  
  Serial.begin(9600);
    // set the digital pin as output:
  pinMode(LED_PIN, OUTPUT);
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  BT05.begin(9600);
}

void loop() {  
  int c;
    
  if (BT05.available()) {
      c = BT05.read();  
      Serial.print("Received from Bluetooth Device: ");
      Serial.println(c);
      switch(c) { 
        //case 48: /* Number 0 */
        case '0':
              Serial.println("  off");
              digitalWrite(LED_PIN, LOW);
              break;      
        //case 49: /* Number 1 */
        case '1':
              Serial.println("  on");
              digitalWrite(LED_PIN, HIGH);
              break;
        default:
              Serial.println("case default");
              break;
      }
  }
}
