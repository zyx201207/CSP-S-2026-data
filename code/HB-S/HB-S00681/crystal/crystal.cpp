#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, l, r, ans, a[500010], f[500010];
bool check(int mid)
{
	for (int i = mid; i <= n; i++)
		if (f[i] - f[i - mid + 1] - (a[i] - a[i - mid + 1]) * (i - mid) <= m)
			return true;
	return false;
}
signed main()
{
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m), l = 1, r = n;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1, ans = mid;
		else
			r = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}
