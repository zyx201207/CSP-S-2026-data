#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		
		if(s1[1]==s2[1])
		{
			
			if((s1[2]=='D'&&s2[2]=='E')||(s2[2]=='D'&&s1[2]=='E')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='C'&&s1[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C'))
			{
				
				if(s1[2]+1==s2[2])
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
}
