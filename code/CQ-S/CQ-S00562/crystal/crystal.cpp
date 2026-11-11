#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
// bool __st__;
ll n, m;
ll a[N], pre[N];
int ef(int idx)
{
	int l = 0, r = idx - 1, ans = idx - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (a[idx] * (idx - mid) - (pre[idx] - pre[mid]) <= m)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return ans;
}
// bool __ed__;
// void PrintMem() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
	// PrintMem();
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		ans = max(ans, i - ef(i));
	cout << ans << '\n';
	return 0;
} // 14: 37