#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];
int solve() {
	for (int i = 2; i <= n; i ++) {
		m -= (i - 1) * (a[i] - a[i - 1]);
		if (m < 0)
			return i - 1;
	}
	return n;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	cout << solve() << endl;
	return 0;
}