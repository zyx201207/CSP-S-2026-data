#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
ll c,t,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ll ans=0;
		memset(x,0,sizeof(x));
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
		}
		ll d1=x[2]-x[1];
		ll cnt=d/d1;
		for(int i=1;i<=n;i++)
		{
			if(i+cnt*2-1 <= n)
			{
				ans+=cnt/2;
			}
			else
			{
				ll a=n-i;
				if(cnt & 1)
				{
					ans+=(cnt-a)/2;
				}
				else
				{
					ans+=(cnt-1-a)/2;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
