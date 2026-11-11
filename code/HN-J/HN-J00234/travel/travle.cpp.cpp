#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1[2],a2[2],b1[3],b2[3];
	for(int i=0;i<2;i++) cin>>a1[i];
	for(int i=0;i<3;i++) cin>>b1[i];
	for(int i=0;i<2;i++) cin>>a2[i];
	for(int i=0;i<3;i++) cin>>b2[i];
	if(a1[0]!=a2[0]||a1[1]!=a2[1])
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')
			{
				if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')
				{
					if(b1[2]=='B'||b2[2]=='B')
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
				else
				{
					cout<<"1100";
					return 0;
				}
			}
			else if(b2[2]=='D'||b2[2]=='E')
			{
				cout<<"1111";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		} 
	}
}
