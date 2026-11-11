// Time: 16:15
# include <unordered_map>
# include <algorithm>
# include <iostream>
# include <vector>
# include <queue>
# define p1 first
# define p2 second
# define iL inline
# define ll long long
# define PIL pair<int,ll>
# define PLI pair<ll,int>
//# define MULTEST
# define FILE
using namespace std;
const int N = 5e5 + 5,M = 505;
const ll inf = 1e18;
int n,m; ll a[N],dis[M][M];
int idx; vector<PIL> adj[N + M];

ll diss[M + 2];
unordered_map<int,int> mp;
vector<PIL> adjj[M + 2];
iL ll dij(int s,int t){
	// Prepare Nodes
	int id = 2;
	mp.clear(); mp[s] = 1,mp[t] = 2;
	for (auto qwq : adj[s]){
		int uu = qwq.p1;
		if (!mp[uu])
			mp[uu] = ++id;
	}for (auto qwq : adj[t]){
		int uu = qwq.p1;
		if (!mp[uu])
			mp[uu] = ++id;
	}
	// Prepare Edges
	for (int i = 1;i <= id;i++)
		adjj[i].clear();
	for (auto qwq : adj[s]){
		int uu = qwq.p1;
		ll wu = qwq.p2;
		adjj[mp[uu]].push_back({1,wu}),
		adjj[1].push_back({mp[uu],wu});
	}for (auto qwq : adj[t]){
		int uu = qwq.p1;
		ll wu = qwq.p2;
		adjj[mp[uu]].push_back({2,wu}),
		adjj[2].push_back({mp[uu],wu});
	}for (auto qwq : adj[s]){
		int uu = qwq.p1;
		for (auto qvq : adj[t]){
			int vv = qvq.p1;
			if (uu == vv) continue;
			adjj[mp[uu]].push_back({mp[vv],dis[uu - n][vv - n]}),
			adjj[mp[vv]].push_back({mp[uu],dis[uu - n][vv - n]});
		}
	}
	// Prepare Dij
	for (int i = 2;i <= id;i++) diss[i] = inf;
	priority_queue<PLI,vector<PLI>,greater<PLI>> pq;
	pq.push({0,1});
	// Execute!
	while (!pq.empty()){
		int u = pq.top().p2;
		pq.pop();
		for (auto qwq : adjj[u]){
			int v = qwq.p1;
			ll w = qwq.p2;
			if (diss[v] > diss[u] + w)
				diss[v] = diss[u] + w,
				pq.push({diss[v],v});
		}
	}return diss[2];
}iL void solve(){
	int q;
	cin >> m >> m >> n >> q >> q;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= m;j++)
			dis[i][j] = inf;
	for (int i = 1,len;i <= m;i++){
		cin >> len;
		while (len--){
			int u; ll w;
			cin >> u >> w;
			adj[i + n].push_back({u,w}),
			adj[u].push_back({i + n,w});
		}
	}for (int i = 1;i <= n;i++){
		for (auto qwq : adj[i]){
			int u = qwq.p1 - n;
			ll wu = qwq.p2;
			for (auto qvq : adj[i]){
				int v = qvq.p1 - n;
				ll wv = qvq.p2;
				if (u == v) continue;
				dis[u][v] = dis[v][u] = min(dis[u][v],wu + wv);
			}
		}
	}for (int k = 1;k <= m;k++)
		for (int i = 1;i <= m;i++)
			for (int j = i + 1;j <= m;j++)
					dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while (q--){
		int u,v;
		cin >> u >> v;
		cout << a[u] + a[v] + dij(u,v) << '\n';
	}
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	# ifdef FILE
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	# endif
	int ___ = 1;
	# ifdef MULTEST
	cin >> ___;
	# endif
	while (___--)
		solve();
	return 0;
}
