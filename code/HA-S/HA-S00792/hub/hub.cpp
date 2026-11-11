#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define qep(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 1000010;
int cs;
int n, k, ans, f[N], dis[N], dep[N], fa[N];
vector <int> g[N], vec;
bool vis[N];

void dfs2(int u, int ff) {
	fa[u] = ff; dep[u] = dep[ff] + 1;
	for(int &v : g[u]) {
		if(v == ff) continue;
		dfs2(v, u);
	}
}

int fd(int x) {
	return x == f[x] ? x : f[x] = fd(f[x]);
}

void mg(int x, int y) {
	x = fd(x); y = fd(y);
	if(x != y) f[x] = y;
}

int dist(int u, int v) {
	int res = 0;
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]) res ++, u = fa[u];
	while(u != v) {
		res += 2;
		u = fa[u]; v = fa[v];
	}
	return res;
}

bool check(vector <int> &vec) {
	rep(i, 1, n) f[i] = i;
	for(int &u : vec) {
		for(int &v : g[u]) {
			if(vis[v]) mg(u, v);
		}
	}
	int cnt = 0;
	for(int &u : vec) {
		if(fd(u) == u) cnt ++;
	}
	if(cnt > 2) return 0;
	return 1;
}

void dfs(int now, int lst) {
	if(now == k) {
		if(check(vec)) {
			rep(i, 1, n) dis[i] = N;
			rep(i, 1, n) {
				for(int &j : vec) {
					dis[i] = min(dis[i], dist(i, j));
				}				
			}
			int res = 0;
			rep(i, 1, n) res = max(res, dis[i]);
			ans = min(ans, res);
		}
		return;
	}
	rep(i, lst, n) {
		vec.pb(i); vis[i] = 1;
		dfs(now + 1, i + 1);
		vec.pop_back(); vis[i] = 0;
	}
} 

void solution() {
	cin >> n >> k;
	rep(i, 1, n) g[i].clear();
	vec.clear();
	rep(i, 2, n) {
		int u, v; cin >> u >> v;
		g[u].pb(v); g[v].pb(u);
	}
	if(k == n) {
		cout << "0\n";
		return;
	}
	if(k == n - 1 || k == n - 2) {
		cout << "1\n";
		return;
	}
	dfs2(1, 0);
	ans = N; dfs(0, 1);
	cout << ans << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin >> cs >> tt;
	while(tt --) solution();
	return 0;
}

