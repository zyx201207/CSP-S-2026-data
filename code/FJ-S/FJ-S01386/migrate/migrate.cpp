#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define int long long
int cnt[MAXN], a[MAXN], n, d, ans;

void solve()
{
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int r = 1; r <= n; r++)
	{
		for (int i = 1; i <= r; i++) cnt[i] = 0;
		int l = r, last_l = r;
		while (l > 0)
		{
			if (a[last_l] - a[l] > d) break;
			l--;
		}
		if (l == 0) continue;
		for (int i = l + 1; i <= r; i++) cnt[i] = 1;
		
		while (1)
		{
			for (int p = last_l; p > l; p--) 
			{
				for (int k = l; k >= 1; k--)
				{
					if (a[p] - a[k] > d) 
					{
						break;
					}
					cnt[k] += cnt[p];
				} 
			}
			last_l = l;
			while (l > 0)
			{
				if (a[last_l] - a[l] >= d) break;
				l--;
			}
			if (l == 0) 
			{
				break;
			}
		}
		
		for (int i = 1; i <= r; i++) 
			if (cnt[i] == 2) 
			{
				ans++;
			}
	}
	cout << ans << "\n"; 
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


