#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	long long i,j,x=0;
	for(i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			x=1;
		}
	}
	if(x==1)
	{
		cout<<"0000";
		return 0;
	}
	x=0;
	for(i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			x=1;
		}
	}
	if(x==1)
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	else
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[2]=='A')
	{
		if(s2[2]!='B')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='B')
	{
		if(s2[2]!='A'||s2[2]!='C')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='C')
	{
		if(s2[2]!='B')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='D')
	{
		if(s2[2]!='F')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='F')
	{
		if(s2[2]!='D')
		{
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
}
