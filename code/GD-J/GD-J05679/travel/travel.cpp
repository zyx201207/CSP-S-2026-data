#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,c;
string b,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		if(b[0]*10+b[1]==d[0]*10+d[1])
		{
			if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D')
			{
				if(b[2]<='C'&&abs(b[2]-d[2])==1||b[2]>='D')
				{
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
