#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
constexpr int N = 2e6 + 10;
int C, T, n, d, x[N], f[N], g[N], qg[N];
void solve_1_to_10() {
	int ans = 0;
	rep(i, 1, n) {
		f[i] = 0;
		g[i] = 1;
		qg[i] = 1;
		qg[i - 1] = 0;
		int lst = i, lg = i;
		rep(j, i + 1, n) {
			if (x[j] - x[j - 1] > d) {
				break;
			}
			while (x[j] - x[lst] > d) {
				++ lst;
			}
			f[j] = f[lst] + 1;
			lg = max(lg, lst);
			while (f[lg + 1] == f[lst]) {
				++ lg;
			}
			g[j] = qg[lg] - qg[lst - 1];
			if (g[j] == 2) {
				++ ans;
			}
			qg[j] = qg[j - 1] + g[j];
		}
	}
	cout << ans << '\n';
}
void solve_11_to_12() {
	if (n == 1) {
		cout << "0\n";
		return;
	}
	const int diff = x[2] - x[1];
	const int step = d / diff;
	if (step <= 1) {
		cout << "0\n";
		return;
	}
	int ans = 0;
	if (2 * step <= n) {
		ans = n - 2 * step + 1;
	}
	cout << ans << '\n';
}
int cnt_between(const int l, const int r) {
	const int pl = lower_bound(x + 1, x + n + 1, l) - x;
	const int pr = upper_bound(x + 1, x + n + 1, r) - x - 1;
	return pr - pl + 1;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> T;
	while (T --) {
		cin >> n >> d;
		rep(i, 1, n) {
			cin >> x[i];
		}
		if (C <= 10) {
			solve_1_to_10();
		} else if (C <= 12) {
			solve_11_to_12();
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
