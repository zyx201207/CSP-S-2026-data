//GZ-S00127 ½ªÃú²Ó 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 4e3 + 5, MAXP = 20;
const int INF = 0x3f3f3f3f;
int C, T, n, k, ans = INF, dis[MAXN][MAXN], dsu[MAXN];
vector <int> adj[MAXN];
int prt[MAXN][MAXP], dep[MAXN];

void dfs(int u, int f){
	dep[u] = dep[f] + 1, prt[u][0] = f;
	for(int p = 1; (1 << p) <= dep[u]; p++)
		prt[u][p] = prt[prt[u][p - 1]][p - 1];
	for(int v : adj[u])
		if(v != f) dfs(v, u);
}
int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for(int p = MAXP - 1; p >= 0; p--)
		if(dep[u] - dep[v] >= (1 << p)) u = prt[u][p];
	if(u == v) return u;
	for(int p = MAXP - 1; p >= 0; p--)
		if(prt[u][p] != prt[v][p]) u = prt[u][p], v = prt[v][p];
	return prt[u][0];
}
int dist(int u, int v){ return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

int find(int u){ return u == dsu[u] ? u : (dsu[u] = find(dsu[u])); }
void unite(int u, int v){
	dsu[find(u)] = find(v);
}
vector <int > v;
bool chs[MAXN];
int calc(){
	int ret = 0, p = k;
	for(int i = 1; i <= n; i++) dsu[i] = i;
	for(int j = 1; j <= n; j++) 
		if(chs[j]) v.push_back(j);
	for(int i = 1; i < v.size(); i++)
		if(find(v[i - 1]) != find(v[i])) p--, unite(v[i - 1], v[i]);
	if(p > 2) return INF;
	for(int i = 1; i <= n; i++){
		int mn = INF;
		for(int j = 1; j <= n; j++)
			if(chs[j]) mn = min(mn, dist(i, j));
		ret = max(ret, mn);
	}
	return ret;
}
void dfsx(int pos, int c){
	if(c == k){
		ans = min(ans, calc());
		return ;
	}
	if(pos > n) return ;
	chs[pos] = 1;
	dfsx(pos + 1, c + 1);
	chs[pos] = 0;
	dfsx(pos + 1, c);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while(T--){
		ans = INF;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) adj[i].clear();
		memset(chs, 0, sizeof(chs));
		for(int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		dfs(1, 0);
		if(C <= 3){
			dfsx(1, 0);
			cout << ans << "\n";
		}
	}
	return 0;
} 
