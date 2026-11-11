#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<1;
		if(c2.substr(0,2)==s2.substr(0,2))
		{
			cout<<1;
			if(c2[2]==s2[2]||((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				cout<<1;
				if((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))
				{
					cout<<1;
					return 0;
				}
				else
				{
					if(c2[2]=='A'||c2[2]=='C')
					{
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
					else if(c2[2]=='B')
					{
						cout<<1;
						return 0;
					}
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<0;
			if(c2[2]==s2[2]||((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				cout<<"10";
				return 0;
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
		cout<<"0000";
		return 0;
	}
	return 0;
}
