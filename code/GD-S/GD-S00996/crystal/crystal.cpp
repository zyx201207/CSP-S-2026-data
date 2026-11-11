#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
int f[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] + a[i];
	}
	int ans = 0;
	int l, r, mid, mx;
	for(int i = 1; i <= n; i++)
	{
		l = 1, r = i;
		mx = i;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(1ll * a[i] * (i - mid + 1) - (f[i] - f[mid - 1]) <= m)
			{
				mx = min(mx, mid);
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - mx + 1);
	}
	cout << ans;
	return 0;
}
