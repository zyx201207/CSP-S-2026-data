#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mk make_pair
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;
const int N = 1e6 + 10, inf = 1e18, M = 2e6 + 10;
int cid, T, n, k, head[N], ne[M], to[M], id;
void add(int x, int y) {
	to[++id] = y, ne[id] = head[x], head[x] = id;
}
int dep[N], siz[N], top[N], son[N], fa[N]; pii nds[N];
void dfs1(int u, int f) {
	dep[u] = dep[f] + 1, fa[u] = f, siz[u] = 1;
	for(int i = head[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	if(!son[u]) return ;
	dfs2(son[u], tp);
	for(int i = head[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return (dep[x] < dep[y] ? x : y);
}
void work7() {
	int mn = inf;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int num = 0;
			for(int k = 1; k <= n; k++) {
				if(k == i || k == j) continue;
				num = max(num, min(dep[i] + dep[k] - dep[LCA(i, k)], dep[k] + dep[j] - dep[LCA(k, j)]) - 1);
			}
			mn = min(mn, num);
		}
	}
	cout << mn << "\n";
}
bool chs[N];
struct edge { int x, y; } e[N];
int bfa[N], fid[N];
int find(int x) {
	return (bfa[x] == x ? x : bfa[x] = find(bfa[x]));
}
bool check() {
	for(int i = 1; i <= n; i++) bfa[i] = i;
	for(int i = 1; i < n; i++) {
		int x = e[i].x, y = e[i].y;
		if(!chs[x] || !chs[y]) continue;
		int fx = find(x), fy = find(y);
		bfa[fx] = fy;
	}
	int len = 0;
	for(int i = 1; i <= n; i++) if(chs[i]) fid[++len] = find(i);
	sort(fid + 1, fid + len + 1);
	int cnt = 0;
	for(int i = 1; i <= len; i++) cnt += (fid[i] != fid[i - 1]);
	return (cnt <= 2);
}
int calc(int s) {
	int num = 0;
	for(int i = 1; i <= n; i++) {
		if(chs[i]) continue;
		int mn = inf;
		for(int k = 1; k <= n; k++) {
			if(chs[k]) {
//				if(s == 10) cout << "\n sdsd " << i << " " << k << " " << LCA(i, k) << " " << dep[i] + dep[k] - dep[LCA(i, k)] - 1 << "\n";
				int lca = LCA(i, k);
				if(lca == i) {
					mn = min(mn, dep[k] - dep[i]);
					continue;
				}
				if(lca == k) {
					mn = min(mn, dep[i] - dep[k]);
					continue;
				}
				mn = min(mn, dep[i] + dep[k] - dep[lca] - 1);
			}
		}
		num = max(num, mn);
	}
	return num;
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) head[i] = son[i] = siz[i] = top[i] = fa[i] = 0;
	for(int i = 1; i <= id; i++) to[i] = ne[i] = 0;
	id = 0;
	for(int i = 1, x, y; i < n; i++) {
		cin >> x >> y; e[i] = {x, y};
		add(x, y), add(y, x);
	}
	dfs1(1, 0), dfs2(1, 1);
	if(cid == 7) return work7();
	int mn = inf;
//	cout << "----------------------------------\n";
	for(int s = 0; s < (1ll << n); s++) {
		if(__builtin_popcount(s) != k) continue;
		for(int i = 1; i <= n; i++) chs[i] = ((s >> i - 1) & 1);
		if(check()) {
			mn = min(mn, calc(s));
//			cout << s << " " << calc(s) << "\n";
		}
	}
	cout << mn << "\n";
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cid >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
我去了我假了 
*/
