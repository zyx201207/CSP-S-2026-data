#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull n,d;
ll a[2000005];
ull sum[2000005];
ull cnt(int l,int r)
{
	ll p = (r-l+1)%d;
	return p==0 ? d : p;
}
void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i]=sum[i-1]+a[i];
	}
	ull ans = 0;
	for(int l = 1;l <= n;l++)
	{
		for(int r = l;r <= n;r++)
		{
			if(cnt(l,r)==2)
			{
				ans++;
			}
		}
	}
	cout << ans <<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin >> c >> t;
	while(t--)
	{
		solve();
	}
}
