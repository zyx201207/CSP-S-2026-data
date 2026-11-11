#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e5 + 5;

int n, ans;
ll k, a[N], sum[N];
ll calc(ll l, ll r) { return sum[r] - sum[l - 1]; }

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l < r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - calc(mid, i) <= k) r = mid;
			else l = mid + 1;
		} ans = std::max(ans, i - r + 1);
	} printf("%d", ans);
	return 0;
}
