#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], b[N];
inline bool check(int x)
{
	int p = a[x], sum = 0;
	for (int i = 1; i <= x; i++) if (sum + p - a[i] > m) return false; else sum += p - a[i];
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
//	reverse(a + 1, a + 1 + n);
//	for (int i = 1; i < n; i++) b[i] = a[i] - a[i + 1];
//	for (int i = 1; i <= n; i++) b[i] += b[i - 1];
//	for (int i = 1; i <= n; i++) b[i] += b[i - 1];
//	for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
//	int l = 1, r = 1, ans = 0;
//	while (r <= n)
//	{
//		while (r <= n && b[r] - b[l] < m) r++;
//		ans = max(ans, r - l), l++;
//	}
//	cout << ans << '\n';
	int l = 0, r = n, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
//		cout << l << ' ' << r << ' ' << mid << ' ' << ans << '\n';
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
