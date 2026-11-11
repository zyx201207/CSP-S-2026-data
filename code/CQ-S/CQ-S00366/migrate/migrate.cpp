#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int C, T, n, D, ans, a[N], nxt[N], vis[N], f[N], g[N];

inline bool check () {
	for (int i = 3; i <= n; ++i)
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) return 0;
	return 1;
}

inline void solve () {
	cin >> n >> D; ans = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	if (n <= 5000) {
		for (int i = 1; i <= n; ++i) {
			int l = i, r = n, mid, res;
			while (l < r) {
				mid = (l + r) >> 1;
				if (a[mid] - a[i] <= D) l = mid + 1, res = mid;
				else r = mid - 1;
			}
			if (res != n && a[res + 1] - a[i] <= D) res++;
			if (res != i && a[res] - a[i] > D) res--;
			nxt[i] = res;
		}
		for (int i = 1; i <= n; ++i) {
			if (nxt[i - 1] != nxt[i]) vis[i] = 1;
			else vis[i] = vis[i - 1] + 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) f[j] = n + 1, g[j] = 0;
			int lst = i; f[i] = 0, g[i] = 1;
			for (int j = i + 1; j <= n; ++j) {
				while (a[j] - a[lst] > D) lst++;
				f[j] = f[lst] + 1; g[j] = g[lst];
				if (lst + 1 < j && f[lst + 1] == f[lst]) g[j] += g[lst + 1];
				if (lst + 2 < j && f[lst + 2] == f[lst]) g[j] += g[lst + 2];
				if (g[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
		return ;
	}
	
	if (check () == 1) {
		int d = a[2] - a[1];
		int maxn = D / d;
		if (maxn <= 1) { cout << "0\n"; return ; }
		int len = maxn + maxn - 1;
		ans = max (0ll, n - len);
		cout << ans << '\n';
		return ;
	}
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> C >> T;
	while (T--) solve ();
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
