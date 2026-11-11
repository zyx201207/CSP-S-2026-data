#include<bits/stdc++.h>
using namespace std;
string a,c;
char b[5],d[5];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		int b1=b[0]-'0',b2=b[1]-'0';
		int d1=d[0]-'0',d2=d[1]-'0';
		if(b1==d1&&b2==d2)
		{
			cout<<"1";
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))||((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')))
			{
				cout<<"00";
			}
			else
			{
				cout<<"1";
				int je=(b[2]-'A')-(d[2]-'A');
				if(je==1||je==-1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
} 
