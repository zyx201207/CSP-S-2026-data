#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string s,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>s;
	cin>>b;
	cin>>k;
	c=(s[0]-'0')*10+(s[1]-'0');
	d=(k[0]-'0')*10+(k[1]-'0');
	if(a==b) cout<<1;
	else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(c==d) cout<<1;
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')
	{
		if(k[2]=='A'||k[2]=='B'||k[2]=='C')
		cout<<1;
		else
		{
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	else
	{
	if(s[2]=='D'||s[2]=='F')
	{
		if(k[2]=='D'||k[2]=='F')
		cout<<1;
		else{
		cout<<0;
		cout<<0;
		return 0;
	    }
	}	
	}
	if(s[2]=='A'&&k[2]=='B'||s[2]=='B'&&k[2]=='C'||s[2]=='C'&&k[2]=='B'||s[2]=='B'&&k[2]=='A')
	{
		cout<<1;
	}
	else
	{
		if(s[2]=='D'&&k[2]=='F'||s[2]=='F'&&k[2]=='D')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
