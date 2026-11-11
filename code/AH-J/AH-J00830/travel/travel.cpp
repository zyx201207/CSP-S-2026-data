#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,q,w,e;
	int n=0,t=0;
	cin>>s>>q>>w>>e;
	s=' '+s;
	s+=' ';
	s+=q;
	s+=' ';
	s+=w;
	s+=' ';
	s+=e;
	n=(s[1]-'0')*10+(s[2]-'0');
	t=(s[8]-'0')*10+(s[9]-'0');
	if(n==t)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	n=0,t=0;
	n=(s[4]-'0')*10+(s[5]-'0');
	t=(s[11]-'0')*10+(s[12]-'0');
	if(n==t)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((s[6]=='A'&&s[13]=='C')||(s[13]=='A'&&s[6]=='C')||(s[6]=='A'&&s[13]=='B')||(s[13]=='A'&&s[6]=='B')||(s[6]=='B'&&s[13]=='C')||(s[13]=='B'&&s[6]=='C')||(s[6]=='D'&&s[13]=='F')||(s[13]=='D'&&s[6]=='F'))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((s[6]=='A'&&s[13]=='B')||(s[13]=='A'&&s[6]=='B')||(s[6]=='B'&&s[13]=='C')||(s[13]=='B'&&s[6]=='C')||(s[6]=='D'&&s[13]=='F')||(s[13]=='D'&&s[6]=='F'))
	{
		cout<<1;
		return 0;
	}
	else
		cout<<0;
	return 0;
}
