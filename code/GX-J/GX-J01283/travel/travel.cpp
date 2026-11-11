#include<bits/stdc++.h>
using namespace std;
int main(){
preopen('travel.in','r',stdin);
preopen('travel.out','w',stdout);
string c1,s1,c2,s2;
string x;
cin>>c1>>s1>>c2>>s2;
int f=0;
for(int i=0;i<c1.size();i++){
if(c1[i]!=c2[i]){
f=1;
}
}
if(f==1){
x=x+'0000';
cout<<x;
return 0;
}else{
x=x+'1';
}
int f1=0;
for(int i=0;i<s1.size()-1;i++){
if(s1[i]!=s2[i]){
f1=1;
break;
}
}
if(f1==1){
x=x+'0';
}else{
x=x+'1';
}
if(f1==0){
if(s1[2]<='c'&&s2[2]<='c'||s1[2]>='d'&&s2[2]>='d'){
x=x+'1';
}else{
x=x+'0';
}
}else{
x=x+'0';
}
if(s1[2]>='d'&&s2[2]>='d'){
x=x+'1';
}else if(s1[2]<='c'&&s2[2]<='c'){
x=x+'1';
}
cout<<x;
