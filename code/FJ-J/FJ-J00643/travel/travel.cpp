#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double
#define endl "\n"
//const int N=1e5+10;
string a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a==c)
	{
		cout << 1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout << 1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
			{
				cout << 1 ;
				if(abs(b[2]-d[2])==1)
				{
					cout << 1;
				}
				else
				{
					cout << 0 ;
					return 0;
				}
			}
			else
			{
				cout << 0 << 0 ;
				return 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0;
			return 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	
	return 0;
}
