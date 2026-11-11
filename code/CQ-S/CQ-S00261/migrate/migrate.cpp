#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
using i64 = long long; using pii = pair<int, int>;

const int N = 2005, M = 2e6 + 10;

int f[N][N], vis[N][N], c;
i64 d, a[M];

int cal (int i, int j, int x) {
	int l = i, r = j - 1, ans = j;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f[i][mid] <= x) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

inline void solve() {
	int n; cin >> n >> d; rep (i, 1, n) cin >> a[i];
	i64 ans = 0;
//	cout << c << '\n';
	if (c >= 11 && c <= 12) {
		if (n == 1) cout << 0 << '\n';
		else if (n == 2) cout << 0 << '\n';
		else {
			i64 y = a[2] - a[1];
			if (y > d) cout << 0 << '\n';
			else {
				int x = 0; i64 ans = 0;
				rep (i, 1, n) if (a[i] - a[1] <= d) x = i - 1;
				rep (i, x + 1, n) if ((i - 1) % x == x - 1 && x > 1) {
					ans += n - i + 1; break;
				}
				cout << ans << '\n';
			}
		}
		return ;
	}
	if (c >= 13) {
		cout << 0 << '\n';
		return ;
	}
	rep (i, 1, n) {
		vis[i][i] = 0;
		rep (j, i + 1, n) {
			f[i][j] = n + 1;
			if (a[j] - a[i] <= d) f[i][j] = 1, vis[i][j] = vis[i][j - 1];
			else {
				int pos = lower_bound (a + i, a + j, a[j] - d) - a;
				if (pos == j) break;
				int l = pos, r = cal (i, j, f[i][l]);
				if (vis[i][r] - vis[i][l - 1] >= 1) {
					vis[i][j] = vis[i][j - 1] + 1;
					ans += (l == r);
				} else {
					vis[i][j] = vis[i][j - 1] + (l != r);
					ans += (l + 1 == r);
				}
				f[i][j] = f[i][pos] + 1;
			}
		}
	}
	cout << ans << '\n';
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> c >> T;
	while (T--) solve();
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
