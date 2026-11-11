#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5, INF = 1e18;
int n, m, a[N],sum, l, r, ans, nd;
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	sum = 0, l = 1, r = 0;
	while (r < n)
	{
		r++;
		sum += a[r];
		nd = (r - l + 1) * a[r] - sum;
		while (l <= r && m < nd)
		{
			sum -= a[l];
			l++;
			nd = (r - l + 1) * a[r] - sum;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}