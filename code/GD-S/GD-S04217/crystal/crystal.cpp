#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500010];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1;i <= n;i ++)
	{
		scanf("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	int l = 1, r = 1, len = 1;
	ll cnt = 0, ans = 0;
	while (r <= n && l <= n)
	{
		ll k = 0;
		if (r < n) k = (a[r + 1] - a[r]) * len + cnt;
		if (m - k >= 0 && r < n)
		{
			r ++;
			len ++;
			cnt = k;
		}
		else
		{
			cnt -= (a[r] - a[l]);
			l ++;
			len --;
		}
		ans = max(len * 1ll, ans);
	}
	printf("%lld", ans);
	return 0;
}
