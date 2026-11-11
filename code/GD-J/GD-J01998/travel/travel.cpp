#include<bits/stdc++.h> 
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<1;
	}else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))
		{
			cout<<1;
			if(s1[0]==s2[0]&&s1[1]==s2[1])
			{
				if(s1[2]-1==s2[2]||s1[2]+1==s2[2])
				{
					cout<<1;
				}else
				{
					cout<<0;
				}
			}else
			{
				cout<<0;
			}return 0;
		}else
		{
			cout<<0<<0;
		}
	}else
	{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
