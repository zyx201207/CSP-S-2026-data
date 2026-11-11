#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define deb(x) cerr << #x << ":" << x << " "
using namespace std;
const int N = 2e5 + 5;
int n, m, x;
int a[N];
int rec[N];
int A[2005][2005];
int vis[N];
void dfs(int cur, int cnt) {
	if (cnt == m) {
		x = max(x, cur);
		deb(cur), deb(x);
		cerr << "\n";
		for (int i = 1; i <= cnt; i ++) {
			cerr << "    ";
			deb(i), deb(rec[i]);
			cerr << "\n";
		}
		return;
	}
	bool flag = 0, fl = 0;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = 1;
			rec[cnt + 1] = a[i];
			dfs((cur & a[i]), cnt + 1);
			vis[i] = 0;
		}
	}
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n <= 20) {
		dfs(2147483647, 0);
		cout << x << "\n";
	} else if (n <= 2000) {
		if (m == 1) {
			int mxn = 0;
			for (int i = 1; i <= n; i ++) 
				mxn = max(mxn, a[i]);
			cout << mxn << "\n";
		} else if (m == n) {
			int cur = a[1];
			for (int i = 1; i <= n; i ++) {
				cur &= a[i];
			}
			cout << cur << "\n";
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= n; j ++) {
					A[i][j] = a[i] & a[j];
					ans = max(ans, A[i][j]);
				}
			}
			cout << ans << "\n";
		}
	} else {
		
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	freopen("and.log", "w", stderr);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
//	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}

