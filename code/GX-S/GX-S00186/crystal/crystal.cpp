#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int n, m, ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int l = 1, r = 1, sum = 0; r <= n;)
	{
		while (r <= n && sum <= m)
			r++, sum += (r - l) * (a[r] - a[r - 1]);
		ans = max(ans, r - l);
		while (l < r && sum > m)
			sum -= a[r] - a[l], l++;
	}
	cout << ans << '\n';
	return 0;
}