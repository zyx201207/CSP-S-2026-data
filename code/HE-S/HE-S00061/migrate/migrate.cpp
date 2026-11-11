#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
#define ll long long
ll c,t,n,d,x[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> x[i];
		//if(c==11 || c==12 || c==0)
		{
			if(x[2]-x[1]>d)
			{
				cout << 0 << '\n';
			}
			else
			{
				ll ans=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						ans++;
					}
				}
				cout << ans << '\n';
			}
		}
	}
	return 0;
} 
