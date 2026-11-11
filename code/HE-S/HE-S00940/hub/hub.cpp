//Oct31==Dec25?
#include <bits/stdc++.h>

using namespace std;
const int N = 110;

int c, T, n, k, tot, cnt, ans;
int head[N], dis[N];
bool vis[N];
struct Map { int to, nxt; } e[N];

void add (int u, int v) {
	e[++tot] = {v, head[u]}, head[u] = tot;
}

void ck (int u, int fa) {
	if (vis[u] && !vis[fa]) cnt++;
	for (int i = head[u]; i; i = e[i].nxt) 
		if (e[i].to != fa) ck (e[i].to, u);
}

void dfs (int u, int fa, int dep) {
	dis[u] = min (dis[u], dep);
	for (int i = head[u]; i; i = e[i].nxt) 
		if (e[i].to != fa) dfs (e[i].to, u, dep + 1);
}

int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= tot; ++i) e[i] = {0, 0};
		for (int i = 1; i <= n; ++i) head[i] = 0;
		tot = 0, ans = 1e6;
		for (int i = 1, u, v; i < n; ++i) 
			cin >> u >> v, add (u, v), add (v, u);
		for (int i = 0; i < (1 << n); ++i) {
			int s = i, sum = 0;
			while (s) {
				if (s & 1) sum++;
				s >>= 1;
			} if (sum != k) continue;
			for (int j = 0; j < n; ++j) vis[j + 1] = ((i >> j) & 1);
			cnt = 0, ck (1, 0);
			if (cnt > 2) continue;
			for (int j = 1; j <= n; ++j) dis[j] = 1e6;
			for (int j = 1; j <= n; ++j) if (vis[j]) dfs (j, 0, 0);
			int mx = 0;
			for (int j = 1; j <= n; ++j) mx = max (mx, dis[j]);
			ans = min (ans, mx);
		} cout << ans << '\n';
	}
	return 0;
}
