#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,ca,sb;
	cin>>c>>s>>ca>>sb;
	if(c==ca)
		cout<<1;
	else
		cout<<0;
	if(c==ca)
	{
		if(s[1]==sb[1])
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
	
		
	int flag=0;
	if(s[1]==sb[1]){
		if(s[2]=='F'&&sb[2]=='D' || s[2]=='D'&&sb[2]=='F')
			flag=1;
		else if(s[2]=='A'&&sb[2]=='B' || s[2]=='A'&&sb[2]=='C' || s[2]=='B'&&sb[2]=='C' || s[2]=='B'&&sb[2]=='A' || s[2]=='C'&&sb[2]=='A' || s[2]=='C'&&sb[2]=='B')
			flag=1;
		
		if(flag==1)
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
	
	int flag2=0;
	if(s[2]=='A'&&sb[2]=='B' || s[2]=='B'&&sb[2]=='C' || s[2]=='F'&&sb[2]=='D' || s[2]=='D'&&sb[2]=='F')
		flag2=1;
		
	if(flag2==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
