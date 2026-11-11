#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

basic_string<int> g[MAXN];

int n, m, d[MAXN], fa[MAXN];

int res[MAXN]; bool ban[MAXN];

void dfs(int u, int f = 0) {
	d[u] = d[f] + 1, fa[u] = f;
	for (int v : g[u]) if (v != f && !ban[v]) dfs(v, u);
}

void calc(int u, int f = 0) {
	d[u] = 0;
	for (int v : g[u]) {
		if (v == f || ban[v]) continue;
		calc(v, u), d[u] = max(d[u], d[v]);
	}
	++d[u];
}

int c1[MAXN], c2[MAXN];

inline 
int solve() {
	for (int i = 0; i < n; i++) res[i] = n;
	for (int i = 1; i <= n; i++) {
		for (int j : g[i]) {
			if (j < i) continue; int p = 0;
			
			ban[j] = 1, dfs(i), p = i;
			for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _; dfs(p);
			for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _;
			for (int _ = d[p] >> 1; _; _--) p = fa[p]; calc(p);
			for (int _ = 1; _ <= n; _++) if (d[_]) ++c1[d[_]];
			for (int _ = n; _ > 1; _--) c1[_ - 1] += c1[_]; ban[j] = 0;
			for (int _ = 1; _ <= n; _++) d[_] = 0;
			
			ban[i] = 1, dfs(j), p = j;
			for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _; dfs(p);
			for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _;
			for (int _ = d[p] >> 1; _; _--) p = fa[p]; calc(p);
			for (int _ = 1; _ <= n; _++) if (d[_]) ++c2[d[_]];
			for (int _ = n; _ > 1; _--) c2[_ - 1] += c2[_]; ban[i] = 0;
			for (int _ = 1; _ <= n; _++) d[_] = 0;
			
			for (int _ = 1; _ <= n; _++) {
				res[_ - 1] = min(res[_ - 1], c1[_] + c2[_]);
			}
			
			for (int _ = 1; _ <= n; _++) c1[_] = c2[_] = 0;
		}
	}
	int p = 0; dfs(1), p = 1;
	for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _; dfs(p);
	for (int _ = 1; _ <= n; _++) if (d[_] > d[p]) p = _;
	for (int _ = d[p] >> 1; _; _--) p = fa[p]; calc(p);
	for (int _ = 1; _ <= n; _++) ++c1[d[_]];
	for (int _ = n; _ > 1; _--) c1[_ - 1] += c1[_];
	for (int _ = 1; _ <= n; _++) res[_ - 1] = min(res[_ - 1], c1[_]);
	for (int _ = 1; _ <= n; _++) d[_] = c1[_] = 0;
	for (int i = 0; i < n; i++) if (res[i] <= m) return i;
}

int T;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (scanf("%*d%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v), g[u] += v, g[v] += u;
		}
		printf("%d\n", solve());
		for (int i = 1; i <= n; i++) g[i].clear();
	}
}
