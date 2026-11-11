#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int f1,f2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(d[2]=='D'||d[2]=='F')
	{
		f2=1;
	}
	if(b[2]=='D'||b[2]=='F')
	{
		f1=1;
	}
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(b[1]!=d[1]||d[0]!=b[0])
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(f1!=f2)
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"1";
				if(b[2]==d[2]+1||d[2]==b[2]+1||(d[2]=='D'&&b[2]=='F')||(d[2]=='F'&&b[2]=='D'))
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
		}
	}
	return 0;
}
//Life no out to get you

