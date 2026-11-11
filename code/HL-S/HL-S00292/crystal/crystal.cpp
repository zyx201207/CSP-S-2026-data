#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans;
bool check(int mid, int i) {
	int cost = a[i] * (i - mid) - (s[i - 1] - s[mid - 1]);
//	cout << "Cur Cost = " << cost << '\n';
	return cost <= m;
}
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	bool spc = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i > 1 and a[i] == a[i - 1]) spc = 0;
		s[i] = s[i - 1] + a[i];
	}
//	cout << check(1, 3) << '\n';
	if (spc and m == 0) {
		cout << 1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i - 1, res = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, i)) {
				r = mid - 1;
				res = mid;
			} else {
				l = mid + 1;
			}
		}
		if (res == -1) continue;
		if (i - res + 1 > ans) {
//			cout << "Cur res = " << res << ", Cur i = " << i << '\n';
			ans = i - res + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
