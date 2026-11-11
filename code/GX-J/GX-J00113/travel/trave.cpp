#include<bits/stdc++.h>
using namespace std;
char a[10];
int main(){
  freopen("trave1.in","r",stdin);
  freopen("trave1.out","w",stdout);
  for (int i=1;i<=10;i++){
      cin>>a[i];
  }
  if (a[1]==a[6] && a[2]==a[7]){
      cout<<"1";
      if(a[3]==a[8] && a[4]==a[9]){
          cout<<"1";
              if (a[5]=="a"){
                  if (a[10]=="b"){
                      cout<<"1";
                  }
              }
              if (a[5]=="b"){
                  if (a[10]=="a"){
                      cout<<"1";
                  }
                  if (a[10]=="c"){
                      cout<<"1";
                  }
                  else{
                      cout<<"0";
                      break;
                  }
              }
              if (a[5]=="c"){
                  if (a[10]=="b"){
                      cout<<"1";
                  }
              }
              else {
                  cout<<"0";
                  break;
              }
              if (a[5]=="d"){
                  if (a[10]=="e"){
                      cout<<"1"<<"1";
                  }
              }
              if (a[5]=="e"){
                  if (a[10]=="d"){
                      cout<<"1"<<"1";
                  }
              }
              else {
                  cout<<"0"<<"0";
                  break;
              }
      }
      else {
          cout<<"0"<<"0"<<"0";
          break;
      }
  }
  else {
      cout<<"0"<<"0"<<"0"<<"0";
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
