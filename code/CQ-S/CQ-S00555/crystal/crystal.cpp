#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int n, m, a[500005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	// int maxn = -INF, minn = INF;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		// minn = min(minn, a[i]);
		// maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000) {
		vector<int> tmp;
		int res1 = 1;
		for (int i = 1; i <= n; i ++) {
			tmp.clear();
			for (int j = 1; j <= i; j ++) {
				if (a[i] >= a[j]) {
					tmp.push_back(a[i] - a[j]);
				}
			}
			sort(tmp.begin(), tmp.end());
			int maxx = m, res = 0;
			for (auto i : tmp) {
				if (maxx >= i) {
					res ++;
					maxx -= i;
				} else {
					break;
				}
			}
			res1 = max(res, res1);
		}
		cout << res1;
		return 0;
	}
	int posl = 1, posr = 1, ans = 1, need = 0;
	while (posl <= posr && posr < n) {
		posr ++;
		// int base = a[posr];
		while (need + (a[posr] - a[posr - 1]) * (posr - posl) > m) {
			need -= a[posr - 1] - a[posl];
			posl ++;
		}
		need += (a[posr] - a[posr - 1]) * (posr - posl);
		ans = max(ans, posr - posl + 1);
	}
	cout << ans;
	// int l = 1, r = n, mid = (l + r) >> 1, ans = -1;
	// while (l < r) {
	// 	if (check(a[mid])) {
	// 		l = mid + 1;
	// 		ans = mid;
	// 		mid = (l + r) >> 1;
	// 	}
	// }
	cerr << "\nTime elapsed:" << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}
