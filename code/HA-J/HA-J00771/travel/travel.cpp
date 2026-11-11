#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,f1=0,f2=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<0;f1=1;}
	else {cout<<1;}
	string s1num = s1.substr(0,2);
	string s2num = s2.substr(0,2);
	if(s1num==s2num&&!f1)cout<<1;
	else{
		cout<<0;
		f2=1;
	}
	string s1sec = s1.substr(2,1);
	string s2sec = s2.substr(2,1);
	char s1c = s1sec[0];
	char s2c = s2sec[0];
	if(s1c>='A'&&s1c<='C'&&s2c>='A'&&s2c<='C'&&!f1&&!f2)
	{
		cout<<1;
	}else if(s1c>='D'&&s1c<='F'&&s2c>='D'&&s2c<='F'&&!f1&&!f2)
	{
		cout<<1;
	}else{
		cout<<0;
	}
	if((s1c=='A'&&s2c=='B')||(s1c=='B'&&s2c=='A') && !f1&&!f2)
	{
		cout<<1;
	}else if((s1c=='C'&&s2c=='B')||(s1c=='B'&&s2c=='C') && !f1&&!f2)
	{
		cout<<1;
	}else if((s1c=='D'&&s2c=='F')||(s1c=='F'&&s2c=='D') && !f1&&!f2)
	{
		cout<<1;
	}else{
		cout<<0;
	}
}