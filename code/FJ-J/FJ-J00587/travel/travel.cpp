#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	int a,b,c,d;
	char e,f;
	cin>>s;
	a=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	b=(s[0] -'0')*10+s[1]-'0';
	e=s[2];
	cin>>s;
	c=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	d=(s[0]-'0')*10+s[1]-'0';
	f=s[2];
	if(a==c){
		if(b==d){
		if(e<'D'&&f<'D'){
			if(abs(e-f)==1||e=='F'&&f=='D'||e=='D'&&f=='F'){
				cout<<1111;
			}else{
				cout<<1110;
			}
		}else{
			cout<<1100;
		}
		}else{
			cout<<1000;
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
