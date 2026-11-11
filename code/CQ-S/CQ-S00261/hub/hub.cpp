#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
using i64 = long long; using pii = pair<int, int>;

const int N = 3e5 + 10;

int n, k; int fa[N];
int res = 1e9;
int find (int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
vector<int> g[N];
int dep[N], par[N];
void dfs (int u) {
	for (int v : g[u]) {
		if (v != par[u]) {
			par[v] = u, dep[v] = dep[u] + 1;
			dfs (v);
		}
	}
}
int cal (int x, int y) {
	if (dep[x] < dep[y]) swap (x, y);
	int ans = 0;
	while (dep[x] != dep[y]) x = par[x], ans++;
	while (x != y) ans += 2, x = par[x], y = par[y];
	return ans;
}

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, T; cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		rep (i, 1, n) g[i].clear();
		rep (i, 1, n - 1) {
			int u, v; cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs (1);
		if (c <= 3) {
			int cur = 1e9;
			rep (S, 0, (1 << n) - 1) {
				if (__builtin_popcount(S) != k) continue;
				rep (i, 1, n) fa[i] = i;
				rep (i, 1, n) {
					if (S >> (i - 1) & 1) {
						for (int v : g[i]) {
							if (S >> (v - 1) & 1) {
								fa[find(i)] = find(v);
							}
						}
					}
				}
				int ans = 0;
				rep (i, 1, n) if (S >> (i - 1) & 1) ans += (find(i) == i);
				if (ans > 2) continue;
				int mi = 0;
				rep (i, 1, n) {
					int mx = 1e9;
					rep (j, 1, n) {
						if (S >> (j - 1) & 1) mx = min(mx, cal(i, j));
					}
					mi = max(mi, mx);
				}
		//		rep (i, 1, n) if (S >> (i - 1) & 1) cout << i << ' ';
			//	cout << ':' << mi << '\n';
				cur = min(cur, mi);
			}
			cout << cur << '\n';
		} else {
			res = 1e9;
			rep (i, 1, n) {
				par[i] = dep[i] = 0;
				dfs (i);
				int mx = 0;
				rep (j, 1, n) mx = max(mx, dep[j]);
				res = min(res, mx);
			}
			cout << res << '\n';
		}
	}
}
/*
[100, 100] + [100, 100] + [56, 56] + [15, 30] = [271, 286]
ÄÜÓĞ WC ´òÂğ 
*/
