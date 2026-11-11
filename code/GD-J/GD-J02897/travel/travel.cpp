#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s[10];
	cin>>c1>>s[1]>>s[2]>>s[3]>>c2>>s[4]>>s[5]>>s[6];
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s[1]==s[4]&&s[2]==s[5])
	{
		cout<<"1";
		if(s[3]=='A'||s[3]=='B'||s[3]=='C')
		{
			if(s[6]=='A'||s[6]=='B'||s[6]=='C')
			{
				cout<<"1";
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else if(s[3]=='D'||s[3]=='F')
		{
			if(s[6]=='D'||s[6]=='F')
			{
				cout<<"1";
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
	}
	else
	{
		cout<<"000";
		return 0;
		
	}
	if(s[3]=='A'&&s[6]=='B'||s[3]=='B'&&s[6]=='C'||s[3]=='B'&&s[6]=='A'||s[3]=='C'&&s[6]=='B'||s[3]=='D'&&s[6]=='F'||s[3]=='F'&&s[6]=='D')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
