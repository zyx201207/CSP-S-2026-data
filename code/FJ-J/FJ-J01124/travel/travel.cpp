#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	bool f;
	cin>>a;
	string s,s1; 
	cin>>s;
	cin>>b;
	cin>>s1;
	if(a==b)
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if(s[0]==s1[0]&&s[1]==s1[1]&&f)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s1[2]=='F'||s1[2]=='D'))
	{
		cout<<0;
		f=0;
	}
	else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s[2]=='F'||s[2]=='D'))
	{
		cout<<0;
		f=0;
	}
	else if(f)
	{
		cout<<1;
	}
	if(f&&(s[2]=='F'||s1[2]=='F'))
	{
		cout<<1;
	}
	else if(f&&(s[2]==s1[2]+1||s[2]==s1[2]-1))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
