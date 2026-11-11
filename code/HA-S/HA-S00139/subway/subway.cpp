#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
const int N = 5e5 + 10, M = 510;
struct edge{
	int u, v;
	ll w;
	bool operator< (edge x) const{return w < x.w;}
}e0[N];
int c, n, m, dm, qm, cnt;
ll wm[N], dis[N];
vector<pair<ll, int>> ta[M];
pair<int, int> q[100005];
vector<pair<int, ll>> e[N];
int fa[N], g[N][20], dep[N];

int ffind(int x){return fa[x] == x ? x : ffind(fa[x]);}
void dfs(int u, int fu){
	for(int i = 1; i <= __lg(n); ++i) g[u][i] = g[g[u][i - 1]][i - 1];
	for(auto val : e[u]){
		int v = val.fi;
		if(v != fu){
			dis[v] = dis[u] + val.se;
			g[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = __lg(dep[x]); i >= 0; --i)
		if(dep[g[x][i]] >= dep[y]) x = g[x][i];
	if(x == y) return x;
	for(int i = __lg(dep[x]); i >= 0; --i){
		if(g[x][i] != g[y][i]){
			x = g[x][i];
			y = g[y][i];
		}
	}
	return g[x][0];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> c >> m >> n >> dm >> qm;
	for(int i = 1; i <= n; ++i){
		cin >> wm[i];
		fa[i] = i;
	}
	for(int i = 1; i <= m; ++i){
		int k;
		cin >> k;
		for(int j = 1; j <= k; ++j){
			int at1, at2;
			cin >> at1 >> at2;
			ta[i].push_back({at2, at1});
		}
	}
	int beg = 2e9;
	for(int i = 1; i <= qm; ++i){
		int u, v;
		cin >> u >> v;
		q[i] = {u, v};
		beg = min({beg, u, v});
	}
	for(int i = 1; i <= m; ++i){
		sort(ta[i].begin(), ta[i].end());
		int bu = -1, bw;
		for(auto val : ta[i]){
			if(bu == -1){
				bu = val.se, bw = val.fi;
				continue;
			}
			e0[++cnt] = {bu, val.se, bw + val.fi};
		}
	}
	int mg = 0;
	for(int i = 1; i <= cnt; ++i){
		int u = e0[i].u, v = e0[i].v;
		ll w = e0[i].w;
		int fu = ffind(u), fv = ffind(v);
		if(fu != fv){
			e[u].push_back({v, w});
			e[v].push_back({u, w});
			fa[fu] = fv;
			if(++mg == n - 1) break;
		}
	}
	dep[beg] = 1;
	dfs(beg, 0);
	for(int i = 1; i <= qm; ++i){
		int x = q[i].fi, y = q[i].se, lca = LCA(x, y);
		cout << wm[x] + wm[y] + dis[x] + dis[y] - 2ll * dis[lca] << '\n';
	}
	return 0;
}

