#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		if(b[0]==d[0]&&b[1]==d[1])
		{
			if('D'==b[2]&&'A'<=d[2]&&d[2]<='C')
			{
				cout<<"1100";
				return 0;
			}
			if('F'==b[2]&&'A'<=d[2]&&d[2]<='C')
			{
				cout<<"1100";
				return 0;
			}
			if('D'==d[2]&&'A'<=b[2]&&b[2]<='C')
			{
				cout<<"1100";
				return 0;
			}
			if('F'==d[2]&&'A'<=b[2]&&b[2]<='C')
			{
				cout<<"1100";
				return 0;
			}
			else
			{
				if(abs(b[2]-d[2])==1)
				{
					cout<<"1111";
					return 0;
				}
				else if(b[2]=='D'&&d[2]=='F')
				{
					cout<<"1111";
					return 0;
				}
				else if(d[2]=='D'&&b[2]=='F')
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
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	return 0;
}
