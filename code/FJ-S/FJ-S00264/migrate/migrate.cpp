#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n, dis[N];
ll d, ans, a[N], cnt[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		ll ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		if(d >= a[n] - a[1])
		{
			cout << "0\n";
			continue;
		}
		a[n + 1] = 1e18;
		if(n <= 5000)
		{
			for(int i = 1;i < n;i++)
			{
				if(a[i + 1] - a[i] > d) continue;	
				for(int j = i;j <= n;j++)
					cnt[j] = dis[j] = 0;
				dis[i] = 0;
				cnt[i] = 1;
				int p = 0;
				for(int j = i;j < n;j++)
				{
					if(a[j + 1] - a[j] > d) break;
					p = upper_bound(a + 1, a + n + 2, a[j] + d) - a - 1;
					for(int k = j + 1;k <= p;k++)
					{
						if(!dis[k]) dis[k] = dis[j] + 1;
						if(dis[k] >= dis[j] + 1) cnt[k] += cnt[j];
					}
				}
				for(int j = i + 1;j <= n;j++)
					if(cnt[j] == 2)
						ans++;
			}
			cout << ans << "\n";
		}else
		{
			ll k = a[2] - a[1];
			ll p = d / k;
			if(p <= 1) cout << "0\n";
			else cout << max(0ll, n - 2 * p + 1) << "\n";
		}
	}
	return 0;
}
