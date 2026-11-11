#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, ans = -1, m, a[500005], sum[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1ll);
	sum[n + 1] = 0x7f7f7f7f7f7f7f7f;
	ll l = 1, r = 1;
	for (l = 1; l <= n; l++)
	{
		while (r <= n && sum[r] - sum[l - 1] <= m)
			r++;
		r--;
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}
