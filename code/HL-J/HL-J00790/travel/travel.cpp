#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int flag=0,flag1=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	   string a1,a2;
	   string s1,s2;
	   int b1,b2;
	   cin>>a1>>s1>>a2>>s2;
	   if(a1!=a2){
	   	cout<<"0000";
	   	return 0;
	   }
	   if(b1==b2){
	   	a=1;
	   }
	   if(s1[0]==s2[0]&&s1[1]==s2[1]){
	   	b=1;
	   }
	   else{
	   	cout<<"1000";
	   	return 0;
	   }
	   if(s1[2]=='A'&&s2[2]=='B'){
	   	c=1;
	   }
	   if(s1[2]=='B'&&s2[2]=='A'){
	   	c=1;
	   }
	   if(s1[2]=='A'&&s2[2]=='C'){
	   	c=1;
	   }
	   if(s1[2]=='C'&&s2[2]=='A'){
	   	c=1;
	   }
	   if(s1[2]=='B'&&s2[2]=='C'){
	   	c=1;
	   }
	   if(s1[2]=='F'&&s2[2]=='D'){
	   	c=1;
	   }
	   if(s1[2]=='D'&&s2[2]=='F'){
	   	c=1;
	   }
	   if(c==0){
	   	cout<<"1100";
	   	return 0;
	   }
	   if(s1[2]=='C'&&s2[2]=='D'){
	   	d=0;
	   	flag=1;
	   }
	   if(s1[2]=='D'&&s2[2]=='C'){
	   	d=0;
	   	flag=1;
	   }
	   if(s1[2]-1==s2[2]||s2[2]-1==s1[2]&&flag==0){
	   	d=1;
	   }
	   if(s1[2]=='D'&&s2[2]=='F'){
	   	d=1;
	   }
	   if(s1[2]=='F'&&s2[2]=='D'){
	   	d=1;
	   }
	   cout<<a<<b<<c<<d;
	   return 0;
}
