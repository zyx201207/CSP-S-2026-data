#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[5]={1,0,0,0,0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(s1[2]=='A'||s1[2]=='C')
		{
			if(s2[1]!=s1[1])
			{
				cout<<"1000";
				return 0;
			}
			if(s2[2]=='B')
			{
				cout<<"1111";
				return 0;
			}
			else
			{
				cout<<"1110";
				return 0;
			}
		}
		if(s2[2]=='A'||s2[2]=='C')
		{
			if(s2[1]!=s1[1])
			{
				cout<<"1000";
				return 0;
			}
			if(s1[2]=='B')
			{
				cout<<"1111";
				return 0;
			}
			else
			{
				cout<<"1110";
				return 0;
			}
		}
		if(s1[2]=='D')
		{
			if(s2[2]=='F')
			{
				cout<<"1111";
				return 0;
			}
			if(s2[1]!=s1[1])
			{
				cout<<"1000";
				return 0;
			}
			else
			{
				cout<<"1100";
			}
		}
		if(s2[2]=='D')
		{
			if(s1[2]=='F')
			{
				cout<<"1111";
				return 0;
			}
			if(s2[1]!=s1[1])
			{
				cout<<"1000";
				return 0;
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
}