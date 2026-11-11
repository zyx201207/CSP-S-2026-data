#include<bits/stdc++.h>
using namespace std;
int n, res = 1;
long long m, a[500005], pre[500005];
int main() {
#ifndef DPSLT_XWX
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
	for (int i = 2; i <= n; ++i) for (int j = max(res - 1, 1); j < i; ++j)
		if (a[i] * j - pre[i - 1] + pre[i - j - 1] <= m) res = max(res, j + 1);
		else break;
	cout << res << '\n';
	return 0;
}
