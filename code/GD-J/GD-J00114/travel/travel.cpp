#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	int la,la1,la2;
	bool u=1;
	cin>>a1>>a2>>b1>>b2;
	if (a1.size()!=b1.size()) 
	{
		cout<<0;
		la=0;
	}
	else
	{
		for (int i=0;i<a1.size();i++)
		{
			if (a1[i]!=b1[i])
			{
				u=0;
				cout<<0;
				la=0;
			}
		}
		if (u)
		{
			cout<<1;
			la=1;
		}
	}
	if (la==0)
	{
		cout<<0;
		la1=0;
	}
	else
	{
		if (a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<1;
			la1=1;
		}
		else
		{
			cout<<0;
			la1=0;
		}
	}
	if (la1==0)
	{
		cout<<0;
		la2=0;
	}
	else
	{
		if ((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='A'&&b2[2]=='C')||(a2[2]=='C'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D'))
		{
			cout<<1;
			la2=1;
		}
		else
		{
			cout<<0;
			la2=0;
		}
	}
	if (la2==0)
	{
		cout<<0;
	}
	else
	{
		if ((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='A')||(a2[2]=='C'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D'))
		{
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
