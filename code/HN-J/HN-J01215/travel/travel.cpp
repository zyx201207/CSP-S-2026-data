#include<bits/stdc++.h>
using namespace std;
int num[2],a=0,b=0,c=0,d=0;
string str1,str2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[10];
	s[0]='A';
	s[1]='B';
	s[2]='C';
	s[3]='D';
	s[4]='E';
	s[5]='F';
	cin>>num[1]>>str1>>num[2]>>str2;
	if(num[1]==num[2]){
		a=1;
	}else{
		cout<<0<<" "<<0<<" "<<0<<" "<<0;
		return 0;
	}
	if(str1[0]==str2[0]&&str1[1]==str2[1]){
		b=1;
	}else{
		b=0;
	}
	if((str1[2]>='A'&&str1[2]<='C')&&(str2[2]>='A'&&str2[2]<='C')){
		c=1;
	}else{
		c=0;
	}
	if((str1[2]>'D'&&str1[2]<='F')&&(str2[2]>'D'&&str2[2]<='F')){
		c=1;
	}else{
		c=0;	
	}
	string cnt1,cnt2;
	if(c==1){
		for(int i=0;i<=5;i++){
			cnt1=str1[2];
			cnt2=str2[2];
			if(cnt1==s[i]&&cnt2==s[i+1]){
				d=1;
			}
			if(cnt2==s[i]&&cnt1==s[i+1]){
				d=1;
			}
			if(cnt1=="C"&&cnt2=="D"){
				d=0;
			}
			if(cnt2=="C"&&cnt1=="D"){
				d=0;
			}
		}	
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d;
	return 0;
} 
