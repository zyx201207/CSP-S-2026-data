#include<bits/stdc++.h>
using namespace std;
string cx1;
string s1;
string cx2;
string s2;
bool b=true;
bool c=true;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1;
cin>>cx1;
cin>>s2;
cin >>cx2;

if(s1[0]== s2[0]and s1[1]==s2[1]){
	cout<<"1";
}
else{
	cout<<"0";
	b=false;
}
if(cx1[0]-'0'==cx2[0]-'0' and cx1[1]-'0'==cx2[1]-'0' and b!=false){
	cout<<"1";
}
else{
	cout<<"0";
	b=false;
}
if((cx1[2]=='C'and cx2[2]=='D') or (cx1[2]=='D' and cx2[2]=='C')){
b=false; 
}
if((cx1[2]<='C' and cx2[2]<='C') or (cx1[2]>='D' and cx2[2]>='D'))b!=false;
if(b!=false)
cout<<"1";
else{
	cout<<"0";
	b=false;
}
if(abs((cx1[2]-'A')-(cx2[2]-'A'))==1 and b!=false){
cout<<"1";
}
else{
	cout<<"0";
}
}

