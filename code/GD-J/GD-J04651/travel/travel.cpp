#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,r1,r2;
	cin>>s1>>s2>>r1>>r2;
	if(s1==r1)
	{
		
		if((s2[0]=='0'&&r2[0]=='0')|(s2[0]=='1'&&r2[0]=='1'))
		{
			if(s2[1]==r2[1])
			{
				if((s2[2]=='D'||s2[2]=='E')&&(r2[2]=='D'||r2[2]=='E'))
				{
				     cout <<"1111";
				     return 0;
				}
				else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'))
				{
					if((s2[2]=='A'||s2[2]=='C')&&(r2[2]=='A'||r2[2]=='C'))
					{
						cout <<"1110";
						return 0;
					}
				    else
				    {
				    	cout <<"1111"; 
					}
				}
				else
				{
					cout <<"1100";
					return 0;
				}
			}
			else
			{
				cout <<"1000";
				return 0;
			}
		}
		else
		{
			cout <<"1000";
			return 0;
		}
	}
	else
	{
		cout <<"0000";
		return 0;
	}
	return 0;
}
