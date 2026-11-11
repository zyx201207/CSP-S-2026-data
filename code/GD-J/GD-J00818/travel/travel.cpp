#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s1[0]&&s1[1]==s2[1])cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	int t1=int(s1[2]),t2=int(s2[2]);
	if(s1[2]=='D')
	{
		if(s2[2]=='F')
		{
			cout<<1;
			flag=1;
		}
		else
		cout<<0;
	}
	else
	if(s1[2]=='F')
	{
		if(s2[2]=='D')
		{
			cout<<1;
			flag=1;
		}
		else
		cout<<0;
	}
	else
	if(s1[2]=='A')
	{
		if(s2[2]=='B'||s2[2]=='C')
		{
			cout<<1;
			flag=1;
		}
		else
		cout<<0;
	}
	else
	if(s1[2]=='B')
	{
		if(s2[2]=='A'||s2[2]=='C')
		{
			cout<<1;
			flag=1;
		}
		else
		cout<<0;
	}
	else
	if(s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B')
		{
			cout<<1;
			flag=1;
		}
		else
		cout<<0;
	}
	if(flag&&abs(t1-t2)==1)cout<<1;
	else
	cout<<0;
}
