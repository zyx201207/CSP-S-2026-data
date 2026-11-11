#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define int long long
#define fi first
#define se second
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 3000010;
inline int read() {
	int a = 0, b = 1; char c = getchar();
	while(c < '0' || c > '9') b = ((c == '-') ? -b : b), c = getchar();
	while(c >= '0' && c <= '9') a = (a << 3) + (a << 1) + (c - '0'), c = getchar();
	return a * b;
}
int C, T, n, K, D[N], d[N], fa[N];
vector<pair<int, int> > e[N];
vector<int> V;
int Ans = inf;
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void dfs(int u, int fa) {
	for(int i = 0, v, w; i < e[u].size(); i++) {
		v = e[u][i].fi, w = e[u][i].se;
		if(v != fa) {
			d[v] = d[u] + w;
			dfs(v, u);
		}
	}
	D[u] = min(D[u], d[u]);
}
void dfs0(int st) {
	if(st == K + 1) {
		for(int i = 1; i <= n; i++) fa[i] = i, D[i] = inf;
		for(int i = 0; i < V.size(); i++) {
			int u = V[i];
			for(int j = 0; j < e[u].size(); j++) {
				int v = e[u][j].fi;
				if(*lower_bound(V.begin(), V.end(), v) == v) 
					if(find(u) != find(v)) fa[find(u)] = find(v);
			}
		}
		int cnt = 0;
		for(int i = 0; i < V.size(); i++) {
			if(find(V[i]) == V[i]) cnt++;
		}
		if(cnt != 2) return;
		for(int i = 0; i < V.size(); i++) d[V[i]] = 0, dfs(V[i], 0);
		int xxx = 0;
		for(int i = 1; i <= n; i++) xxx = max(xxx, D[i]);
		Ans = min(Ans, xxx);
		return;
	}
	if(V.empty()) {
		for(int i = 1; i <= n; i++) {
			V.push_back(i);
			dfs0(st + 1);
			V.pop_back();
		}
		return;
	}
	for(int i = V.back() + 1; i <= n; i++) {
		V.push_back(i);
		dfs0(st + 1);
		V.pop_back();
	}
}
void solve() {
	n = read(), K = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		e[u].push_back({v, 1});
		e[v].push_back({u, 1});
	}
	dfs0(1);
	printf("%lld\n", Ans);
}
void clr() {
	Ans = inf; V.clear();
	for(int i = 1; i <= n; i++) e[i].clear();
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	C = read(), T = read();
	while(T--) {
		solve(); 
		clr();
	}
	return 0;
}
