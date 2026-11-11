#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, inf = 1e18;
int c, T, n, k;
vector<int> g[N];
bitset<15> chosen, vis;
void BFS(int s) {
	queue<int> q;
	q.push(s);
	while (not q.empty()) {
		int u = q.front(); q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : g[u]) {
			if (not chosen[v]) continue;
			q.push(v);
		}
	}
}
int dep[N], fa[N];
void DFS(int u, int from) {
	for (auto v : g[u]) {
		if (v == from) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		DFS(v, u);
	}
}
int getdis(int u, int v) {
	int res = 0;
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] != dep[v]) {
//		cout << '!';
		u = fa[u], res++;
	}
	if (u == v) return res;
	while (u != v) {
//		cout << '!';
		u = fa[u], v = fa[v], res += 2;
	}
	return res;
}
void solveBrute() {
	int ans = inf;
	dep[1] = 1;
	DFS(1, -1);
//	cout << "Dep[1] = " << dep[1] << '\n';
//	cout << "Dis = " << getdis(2, 5) << '\n';
	for (int st = 0; st < (1 << n); st++) {
		if (__builtin_popcountll(st) != k) continue;
		chosen.reset();
		vis.reset();
		for (int j = 1; j <= n; j++) {
			if ((st >> (j - 1)) & 1ll) {
				chosen[j] = 1;
			}
		}
		int cntBlk = 0;
		for (int j = 1; j <= n; j++) {
			if (chosen[j] and not vis[j]) {
				BFS(j);
				cntBlk++;
			}
		}
//		cout << "Cur State = " << st << ":\n";
//		cout << "Cur CntBlk = " << cntBlk << '\n';
		if (cntBlk > 2) continue;
		vector<int> d(n + 5, inf);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (not chosen[j]) continue;
				d[i] = min(d[i], getdis(i, j));
			}
		}
		int dia = 0;
		for (int i = 1; i <= n; i++) {
//			cout << "d[" << i << "] = " << d[i] << '\n';
			dia = max(dia, d[i]);
		}
//		cout << "Therefore, dia = " << dia << '\n';
		ans = min(ans, dia);
	}
	cout << ans << '\n';
}
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		memset(g, 0, sizeof g);
		memset(dep, 0, sizeof dep);
		memset(fa, 0, sizeof fa);
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		if (1 <= c and c <= 3) {
			solveBrute();
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}

