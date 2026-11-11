#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int n, a[MAXN], m, ans;
bool check(int x) {
	int p = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x) {
			p += x - a[i];
			ans++;
		}
	}
	return p <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = -1e12, r = 1e12, t;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			t = mid;
		}
		else
			r = mid - 1;
	}
	check(t);
	cout << ans << "\n";
	return 0;
}
