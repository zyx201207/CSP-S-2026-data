#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string Ra,Rb,Xa,Xb;
cin>>Ra>>Rb>>Xa>>Xb;
int a,b,c;
int A,B,C,D,F;
for(int i=0;i<=18;i++){
if(Ra==Xa){
a=1;
}else{
a=0;
}
cout<<a;
}
int n[a]=Rb;
int m[a]=Xb;
if(n[2]==m[2]){
b+=1;
}else{
b+=0;
}
int l[a]=Rb;
int f[a]=Xb;
if((l[3]==F||l[3]==D)&&(f[3]==F||f[3]==D)){
c+=1;
}else if((l[3]==A||l[3]==B||l[3]==C)&&(f[3]==A||f[3]==B||f[3]==C)){
c=1;
}else{
c=0;
}
cout<<a<<b<<c;
return 0;
}
