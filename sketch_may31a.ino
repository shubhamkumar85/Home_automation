#define BLYNK_TEMPLATE_ID \\ From Blynk Website
#define BLYNK_DEVICE_NAME 
#define BLYNK_AUTH_TOKEN 
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] =  "";\\Wifi name
char pass[] = "";  \\ pwd

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D5, LOW);
    Serial.println("LED ON");
  }
  if(value == 1)
  {
     digitalWrite(D5, HIGH);
     Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D6, LOW);
    Serial.println("LED ON");
  }
  if(value == 1)
  {
     digitalWrite(D6, HIGH);
     Serial.println("LED OFF");
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  
}

void loop()
{
  Blynk.run();
}
