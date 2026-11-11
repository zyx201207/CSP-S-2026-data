#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a1,a2;
	char b1,b2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	cout<<1;
	else
	cout<<0;
	a1=s1[0]+s1[1];
	a2=s2[0]+s2[1];
	if(a1==a2)
	cout<<1;
	else
	cout<<0;
	b1=s1[2];
	b2=s2[2];
	if(a1==a2)
	{
		if(b1=='F'||b1=='D')
		{
			if(b2=='F'||b2=='D')
			cout<<1;
		}
		if(b1=='A'||b1=='B'||b1=='C')
		{
			if(b2=='A'||b2=='B'||b2=='C')
			cout<<1;
		}
	}
	else
	cout<<0;
	if(a1==a2)
	{
		if(b1=='F'||b1=='D')
		{
			if(b2=='F'||b2=='D')
			cout<<1;
		}
		if(b1=='A'||b1=='B')
		{
			if(b2=='A'||b2=='B')
			cout<<1;
		}
		if(b1=='C'||b1=='B')
		{
			if(b2=='C'||b2=='B')
			cout<<1;
		}
	}
	else
	cout<<0;
	return 0;
}
