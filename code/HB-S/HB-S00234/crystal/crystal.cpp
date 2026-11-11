#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], pre[500005], ans;

int calc(int l, int r) {
	return (r - l + 2) * a[r] - (pre[r] - pre[l - 2]);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int p = 2;
	for (int i = 1; i <= n; i++) {
		while (p <= n && calc(i + 1, p) <= m) {
			ans = max(ans, p - i + 1);
			p++;
		}
	}
	cout << ans;
	return 0;
}
/*
l ~ r (r - l + 2) * a[r] - (pre[r] - pre[l - 2])
0 1 2 4
*/
