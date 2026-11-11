#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c[3],s[3];
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2])
	{
		cout<<"1";
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1])
		{
			cout<<"1";
			if(s[1][2]<='C')
			{
				if(s[2][2]<='C')
				{
					cout<<"1";
					if(s[1][2]-s[2][2]==1||s[1][2]-s[2][2]==-1)
					{
						cout<<"1";
						return 0;
					}
					else
					{
						cout<<"0";
						return 0;
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
				if(s[2][2]>='D'&&s[2][2]<='F')
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
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}
