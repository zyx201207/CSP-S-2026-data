#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,pa,pb;
	cin>>a>>pa>>b>>pb;
	if(a==b)
	{
		cout<<"1";
		if(pa[0]==pb[0]&&pa[1]==pb[1])
		{
			cout<<"1";
			if(((pa[2]=='A'||pa[2]=='B'||pa[2]=='C')&&(pb[2]=='A'||pb[2]=='B'||pb[2]=='C'))||((pa[2]=='D'||pa[2]=='E')&&(pa[2]=='D'||pa[2]=='E')))
			{
				cout<<"1";
				if((pa[2]=='D'||pa[2]=='E')&&(pa[2]=='D'||pa[2]=='E'))
				{
					cout<<"1";
				}
				else if((pa[2]=='A'&&pb[2]=='B')||(pa[2]=='B'&&pb[2]=='A')||(pa[2]=='B'&&pb[2]=='C')||(pa[2]=='C'&&pb[2]=='B'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
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