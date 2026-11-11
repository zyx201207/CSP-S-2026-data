#include<bits/stdc++.h>
#define int long long
#define pii pair<ll, int>
#define ll long long
using namespace std;

const int N=5e2+10, M=5e5+10;
ll inf=2e17+50;
vector<int> x[M];
int T=1, c, n, m, d, Q;
int a[M], t[M], val[M];
ll w[N][N], dis[N];
map<pii, int> mp;
vector<pii> G[N];
bool vis[N];
priority_queue<pii, vector<pii>, greater<pii> > q;

void dijkstra(int x) {
	q.push({0, x});
	while(!q.empty()) {
		int u=q.top().second, now=q.top().first; q.pop();
		if(vis[u]) continue; vis[u]=1;
		for(int i=0; i<G[u].size(); i++) {
			int v=G[u][i].first, W=G[u][i].second;
			if(dis[v]>dis[u]+W) dis[v]=dis[u]+W, q.push({dis[v], v});
		}
	}
}

void solve() {
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; i++) cin>>val[i];
	for(int i=1; i<=n; i++) {
		int k; cin>>k;
		for(int j=1; j<=k; j++) cin>>a[j]>>t[j], x[a[j]].push_back(i);
		for(int j=1; j<=k; j++) mp[{a[j], i}]=t[j];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) w[i][j]=inf;
		w[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		for(int u=0; u<x[i].size(); u++) {
			for(int v=1+u; v<x[i].size(); v++) {
				int U=x[i][u], V=x[i][v];
				w[U][V]=min(w[U][V], 0ll+mp[{i, U}]+mp[{i, V}]);
				w[V][U]=min(w[V][U], 0ll+mp[{i, U}]+mp[{i, V}]);
			}
		} 
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(w[i][j]!=inf) G[i].push_back({j, w[i][j]});
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) dis[j]=inf, vis[j]=0; dis[i]=0;
		dijkstra(i);
		for(int j=1; j<=n; j++) w[i][j]=dis[j];
	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) cout<<w[i][j]<<' '; cout<<'\n';
//	}
	
	while(Q--) {
		int u, v;
		ll res=inf; cin>>u>>v;
		for(int i=0; i<x[u].size(); i++) {
			for(int j=0; j<x[v].size(); j++) {
				int U=x[u][i], V=x[v][j];
				res=min(res, 0ll+w[U][V]+mp[{u, U}]+mp[{v, V}]+val[u]+val[v]);
			}
		}
		cout<<res<<'\n';
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while(T--) solve();
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3  3 4 5 7
1 3 1 2
*/
