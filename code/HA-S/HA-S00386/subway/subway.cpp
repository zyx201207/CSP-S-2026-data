#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 5e5 + 505;

int c, n, m, D, Q, w[N], dep[N], f[N][21], vis[N];
ll d[N], dis[N];
struct Edge{
	int p, v;
};
struct node{
	int p;
	ll len;
	int fr, w;
	friend bool operator < (node a, node b){
		return a.len > b.len;
	}
};
vector<Edge>l[N], g[N];
priority_queue<node>q;

void dij(){
	for(int i = 1; i <= m + n; i++) d[i] = 1e18;
	d[1] = 0;
	q.push({1, 0, 1, 0});
	while(q.size()){
		node idx = q.top();
		q.pop();
		int x = idx.p, fr = idx.fr, w = idx.w;
		if(vis[x]) continue;
		vis[x] = 1;
		if(x != fr){
			g[x].pb({fr, w});
			g[fr].pb({x, w});
		}
		for(auto y : l[x]){
			if(d[y.p] > d[x] + y.v){
				d[y.p] = d[x] + y.v;
				q.push({y.p, d[y.p], x, y.v});
			}
		}
	}
}

void dfs(int x, int fa){
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for(int i = 1; i <= 19; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for(auto y : g[x]){
		if(y.p == fa) continue;
		dis[y.p] = dis[x] + y.v;
		dfs(y.p, x);
	}
}

int Lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	int sz = dep[y] - dep[x];
	for(int i = 0; sz; sz >>= 1, i++){
		if(sz & 1) y = f[y][i];
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> D >> Q;
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			int a, t;
			scanf("%d%d", &a, &t);
			l[a].pb({m + i, t});
			l[m + i].pb({a, t});
		} 
	}
	dij();
	dfs(1, 0);
	while(Q--){
		int x, y;
		scanf("%d%d", &x, &y);
		int z = Lca(x, y);
		if(z == x || z == y) printf("%lld\n", abs(dis[y] - dis[x]) + w[x] + w[y]);
		else printf("%lld\n", dis[x] + dis[y] - 2ll * dis[z] + w[x] + w[y]);
	}
	return 0;
}
