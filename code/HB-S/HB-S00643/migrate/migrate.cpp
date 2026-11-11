#include <iostream>
#include <algorithm>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 2e6 + 5;

int c, t, n, d, a[N];

int findl(int id) {
	if (id == 1) return 0;
	int p = lower_bound(a + 1, a + id + 1, a[id] - d) - a;
	if (p == id) return 0;
	if (p == 1) {
		int q = upper_bound(a + 1, a + n + 1, a[1] + d) - a - 1;
		if (q == id) return p;
		return 0;
	}
	return p;
}

int findr(int id) {
	if (id == n) return 0;
	int p = upper_bound(a + id + 1, a + n + 1, a[id] + d) - a - 1;
	if (p == id) return 0;
	if (p == n) {
		int q = lower_bound(a + 1, a + n + 1, a[n] - d) - a;
		if (q == id) return p;
		return 0;
	}
	return p;
}

void solve() {
	cin >> n >> d;
	F(i, 1, n) cin >> a[i];
	if (a[n] - a[1] <= d) {
		cout << 0 << '\n';
		return ;
	}
	int ans = 0;
	F(x, 2, n - 2) {
		int curx = x, cury = x + 1;
		int cnt1 = 0, cnt2 = 0;
//		cout << endl;
		while (1) {
			int k = findl(cury);
//			cout << k << endl;
			if (k) cnt1++, cury = k;
			else break ;
		}
		cout << endl;
		while (1) {
			int k = findr(curx);
//			cout << k << endl;
			if (k) cnt2++, curx = k;
			else break ;
		}
//		cout << endl;
//		cout << x << ' ' << cnt1 * cnt2 << endl;
		ans += cnt1 * cnt2;
	}
	cout << ans << '\n';
	return ;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) solve();
	
	return 0;
}
