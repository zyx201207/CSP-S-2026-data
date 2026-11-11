#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace Creeper{
	const int N = 5005, M = 2e6 + 5;
	int c, n, d, a[M], sum[N][N], nxt[M], ans, s[N];
	int delta = 0;
	bool o = 1;
	void solve() {
		o = 1;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		delta = a[2] - a[1];
		for (int i = 2; i <= n; i++) {
			if (a[i] - a[i - 1] != delta) o = 0;
		}
		if (n <= 5000) {
			ans = 0;
			for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) sum[i][j] = 0;
			for (int i = 1; i <= n; i++) nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1; 
			for (int i = 1; i <= n; i++) {
				int r = i + 1;
				for (int j = nxt[i] + 1; j <= nxt[nxt[i]]; j++) {
					while (r < nxt[i] && a[j] - a[r] > d) r++;
					if (a[j] - a[r] <= d) {
						sum[i][j] += nxt[i] - r;
//						cout << i << ' ' << j << ' ' << r << ' ' << nxt[i] << ' ' << r << '\n';
					}
				}
			}
			ans = 0;
			for (int i = 1; i <= n; i++) {
				int res = 0, now = i, lst = 0, lst2 = 0;
				for (int j = i + 1; j <= n; j++) {
					if (j > nxt[now]) {
						lst2 = lst;
						lst = now;
						now = nxt[now];
						if (lst2) res += sum[lst2][now];
					}
	 				if (nxt[now] < j) break;
					if (res > 1) break;
					if (res + (lst ? sum[lst][j]: 0) == 1) {
//						cout << now << '\n';
//						cout << i << ' ' << j << ' ' << lst << ' ' << (lst ? sum[lst][j]: 0) << '\n';
						ans++;
					}
				}
			}
			cout << ans << '\n';
		} else if (o) {
			ans = 0;
			for (int i = 1; i <= n; i++) nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1; 
			int r = 2;
			for (int j = nxt[1] + 1; j <= nxt[nxt[1]]; j++) {
				while (r < nxt[1] && a[j] - a[r] > d) r++;
				if (a[j] - a[r] <= d) {
					s[j] += nxt[1] - r;
				}
			}
			int res = 0, now = 1, lst = 0, lst2 = 0;
			for (int j = 2; j <= n; j++) {
				if (j > nxt[now]) {
					lst2 = lst;
					lst = now;
					now = nxt[now];
					if (lst2) res += s[now - lst2 + 1];
				}
 				if (nxt[now] < j) break;
				if (res > 1) break;
				if (res + (lst ? s[j - lst + 1]: 0) == 1) {
					ans += (n - j + 1); 
				}
			}
			cout << ans << '\n';
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> Creeper::c >> T;
	while (T--) Creeper::solve();
}
