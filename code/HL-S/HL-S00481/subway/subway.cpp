#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+505;
int c, n, m, d, qq, w[N];
struct edge { int v, w;};
vector<edge> e[N];
int dis[N], vis[N];
void dij (int s) {
	priority_queue<pair<int, int> > q;
	q.push({0, s});
	for (int i=1; i<=m+n; ++i)
		dis[i]=1e16, vis[i]=0;
	dis[s]=0;
	while (q.size()) {
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto i:e[u]) 
			if (dis[i.v]>dis[u]+i.w)
				dis[i.v]=dis[u]+i.w,
				q.push({-dis[i.v], i.v});
	}
}
void sol_baoli1 () {
	for (int u, v; qq--; ) {
		cin >> u >> v; dij(u); 
		cout << w[u]+dis[v]+w[v] << '\n';
	}
}
int ans[1005][1005];
void sol_baoli2 () {
	for (int i=1; i<=m; ++i) {
		dij(i); 
		for (int j=1; j<=m; ++j)
			ans[i][j]=dis[j];
	}
	for (int u, v; qq--; )
		cin >> u >> v, 
		cout << w[u]+ans[u][v]+w[v] << '\n';
}
int dis2[22][N], lst[22][N];
void dij2 (int id) {
	priority_queue<pair<int, int> > q;
	q.push({0, 0});
	for (int i=1; i<=m+n; ++i)
		dis2[id][i]=1e16, vis[i]=0;
	dis2[id][0]=vis[0]=0;
	e[0].clear();
	for (int i=1; i<=n+m; ++i) {
		if (((i>>id)&1)==0) {
			e[0].push_back({i, 0});
		} 	
	}
	while (q.size()) {
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (auto i:e[u]) 
			if (dis2[id][i.v]>dis2[id][u]+i.w) {
				dis2[id][i.v]=dis2[id][u]+i.w;
				q.push({-dis[i.v], i.v});
				if (((u>>id)&1)==0) lst[id][i.v]=u;
				else lst[id][i.v]=lst[id][u];
			}
				
	}
}
void sol_std () {
	for (int i=0; i<=20; ++i) {
		dij2(i);
	}
	for (int u, v; qq--; ) {
		cin >> u >> v;
		int ans=0;
		for (int i=0; i<=20; ++i) {
			if (((u>>i)&1)!=((v>>i)&1)) {
				if ((u>>i)&1) ans+=dis2[i][u];
				else ans+=dis2[i][v];
				for (int j=0; j<=20; ++j) {
					if (((u>>j)&1)!=((lst[i][v]>>j)&1)) {
						if ((u>>j)&1) ans+=dis2[j][u];
						else ans+=dis2[j][lst[i][v]];
						break;
					}
				}
				break;
			}
		}
		cout << ans << '\n';
	}
}
signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> qq;
	for (int i=1; i<=m; ++i) cin >> w[i];
	for (int i=1; i<=n; ++i) {
		int tmp; cin >> tmp;
		for (int j=1, v, w; j<=tmp; ++j) {
			cin >> v >> w;
			e[m+i].push_back({v, w});
			e[v].push_back({m+i, w});
		}
	}
	if (c<=8)sol_baoli1();
	else if (c<=11) sol_baoli2();
	else if (c<=15) sol_baoli1();
	else 
	sol_std();
	return 0;
}