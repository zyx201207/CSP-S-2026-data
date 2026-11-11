#include<bits/stdc++.h>
using namespace std;
int main(){
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2; 
bool flag1=true;
if(c1==c2){
cout<<1;
}else{
cout<<0;
flag1=false;
}
bool flag2=true,flag3=true;
for(int i=0;i<2;i++){
if(s1[i]!=s2[i]){
flag2=false;
}
}
if(flag1&&flag2){
cout<<1;
}else{
cout<<0;
}
if(flag1&&flag2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
cout<<1;
}else{
cout<<0;
flag3=false;
}
int a1=0,a2=0;
for(int i=0;i<2;i++){
if(isdigit(s1[i])){
a1+=s1[i]-'0';
}
if(isdigit(s2[i])){
a2+=s2[i]-'0';
}
}
char b1=s1[2],b2=s2[2];
if(((a1-1==a2||a1+1==a2)&&b1==b2)||((b1-1==b2||b1+1==b2)&&a1==a2)){
if(flag1&&flag3){
cout<<1;
}
else{
cout<<0;
}
}else{
cout<<0;
}
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
return 0;
} 
