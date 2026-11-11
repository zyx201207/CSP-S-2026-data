#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ca,cb,f1,f2;
bool ff1,ff2,ff3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f1=c1[0]-'0';
	f2=c1[1]-'0';
	ca=f1*10+f2;
	f1=c2[0]-'0';
	f2=c2[1]-'0';
	cb=f1*10+f2;
	if(ca==cb)
	{
		cout<<1;
		ff1=1;
	}
	else
	{
		cout<<0;
		ff1=0;
	}
	f1=0,f2=0,ca=0,cb=0;
	if(ff1==0)
	{
		cout<<0;
	}
	else
	{
		f1=s1[0]-'0';
		f2=s1[1]-'0';
		ca=f1*10+f2;
		f1=s2[0]-'0';
		f2=s2[1]-'0';
		cb=f1*10+f2;
		if(ca==cb)
		{
			cout<<1;
			ff2=1;
		}
		else
		{
			cout<<0;
			ff2=0;
		}
	}
	if(ff1==0||ff2==0)
	{
		cout<<0;
	}
	else
	{
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
		{
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			{
				cout<<1;
				ff3=1;
			}
			else
			{
				cout<<0;
				ff3=0;
			}
		}
		else if(s1[2]=='D'||s1[2]=='F')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				cout<<1;
				ff3=1;
			}
			else
			{
				cout<<0;
				ff3=0;
			}
		}
	}
	if(ff1==0||ff2==0||ff3==0)
	{
		cout<<0;
	}
	else
	{
		if(s1[2]=='A')
		{
			if(s2[2]=='B')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
		else if(s1[2]=='B')
		{
			if(s2[2]=='A'||s2[2]=='C')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
		else if(s1[2]=='C')
		{
			if(s2[2]=='B')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
		else if(s1[2]=='D'||s1[2]=='F')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			return 0;
		}
	}
	return 0;
}
