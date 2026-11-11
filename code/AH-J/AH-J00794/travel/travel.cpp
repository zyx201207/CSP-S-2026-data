#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2,s3,s4;
int cnt=0;
cin>>s1>>s2>>s3>>s4;
if(s1==s3){
    cout<<1;
    cnt=1;
}else{
    cout<<0;
    cnt=0;
}
string s2f="";
string s2h="";
for(int i=0;i<s2.size();i++){
    if(s2[i]>='0'&&s2[i]<='9'){
        s2f=s2f+s2[i];
    }
    if(s2[i]>='A'&&s2[i]<='Z'){
        s2h=s2h+s2[i];
    }
}
string s4f="";
string s4h="";
for(int i=0;i<s4.size();i++){
    if(s4[i]>='0'&&s4[i]<='9'){
        s4f=s4f+s4[i];
    }
    if(s4[i]>='A'&&s4[i]<='Z'){
        s4h=s4h+s4[i];
    }
}
int cnt2=0,cnt3=0;
if(s4f==s2f&&cnt==1){
    cout<<cnt;
    cnt2=1;
}else{
cout<<0;
cnt2=0;
}
if(cnt==1&&cnt2==1){
    cnt3=1;
}else{
cnt3=0;
}
if(s2h=="A"&&s4h=="B"||s2h=="B"&&s4h=="A"){
    cout<<cnt3;
}else if(s2h=="A"&&s4h=="C"||s2h=="C"&&s4h=="A"){
    cout<<cnt3;
}else if(s2h=="B"&&s4h=="C"||s2h=="C"&&s4h=="B"){
    cout<<cnt3;
}else if(s2h=="F"&&s4h=="D"||s2h=="D"&&s4h=="F"){
    cout<<cnt3;
}else{
cout<<0;
}
int cnt4=0;
if(cnt==1&&cnt2==1&&cnt3==1){
    cnt4=1;
}
if(s2h=="A"&&s4h=="B"||s2h=="B"&&s4h=="A"){
    cout<<cnt4;
}else if(s2h=="C"&&s4h=="B"||s2h=="B"&&s4h=="C"){
    cout<<cnt4;
}else if(s2h=="D"&&s4h=="F"||s2h=="F"&&s4h=="D"){
    cout<<cnt4;
}else{
cout<<0;
}
return 0;
}
