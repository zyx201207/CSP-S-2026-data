#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}	
	}
	cout<<1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(s1[2]=='A')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<1;
			if(s2[2]=='B')
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<"11";
			return 0;
		}
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<1;
			if(s2[2]=='B')
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(s1[2]=='D')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(s1[2]=='F')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"11";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}

