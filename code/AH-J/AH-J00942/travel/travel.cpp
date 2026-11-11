#include<bits/stdc++.h>
using namespace std;
string x1,x2,z1,z2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>x1>>z1>>x2>>z2;
for(int i=0;i<x1.size();i++){
   if(x1[i]!=x2[i]){
      cout<<"0000";
      return 0;
   }
}
for(int i=0;i<z1.size()-1;i++){
    if(z1[i]!=z2[i]){
      cout<<"1000";
      return 0;
    }
}
if(z1[2]=='F'||z1[2]=='D'&&z2[2]=='D'&&z2[2]=='F'){
   cout<<"1111";
   return 0;
}else if(z1[2]=='A'||z1[2]=='B'||z1[2]=='C'&&z2[2]=='A'||z2[2]=='B'||z2[2]=='C'){
  if(z1[2]=='B'||z2[2]=='B'){
     cout<<"1111";
     return 0;
  }else{
     cout<<"1110";
     return 0;
  }
}else{
   cout<<"1100";
   return 0;
}
return 0;
}
