#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define il inline
#define int long long
using namespace std;
const int N = 5e5+10, M = 5e6+10, inf = 3e18;

int c, n, m, d, q, w[N], k[510], t[510][1010];
int num, h[N], e[M], ne[M], val[M], id[M];
bool A = 1;
vector <pair <int, int>> g[N];
int dis[N];
bool vis[N];
struct node{
	int p, w, lst;
	friend bool operator < (node a, node b){
		return a.w > b.w;
	}
};

il void link(int a, int b, int i){
	e[++num] = b;
	ne[num] = h[a];
	h[a] = num;
	id[num] = i;
}
il void dij(int s, int tt ,int ID){
	memset(dis, 0x7f, sizeof dis); memset(vis, 0, sizeof vis);
	dis[s] = tt;
	priority_queue <node> pq;
	pq.push({s, tt, ID});
	while(pq.size()){
		node u = pq.top(); pq.pop();
		if(vis[u.p]) continue;
		vis[u.p] = 1;
		for(int i = h[u.p]; i; i = ne[i]){
			int v = e[i], idx = id[i];
			if(!u.lst || u.lst != idx){
				int ww = t[u.lst][u.p] + t[idx][v];
				if(dis[u.p] + ww < dis[v]){
					dis[v] = dis[u.p] + ww;
					pq.push({v, dis[v], idx});
				}
			}else{
				dis[v] = dis[u.p];
				pq.push({v, dis[v], u.lst});
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a; cin >> a >> t[i][a];
			g[i].pb({a, t[i][a]});
			if(j > 1){
				link(g[i][j - 1].fi, g[i][j].fi, i);
				link(g[i][j].fi, g[i][j - 1].fi, i);
			}
		}
	}
	while(q--){
		int u, v; cin >> u >> v;
		int ans = inf;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < g[i].size(); j++){
				if(g[i][j].fi == u) dij(u, t[i][u], i);
				ans = min(ans, dis[v]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
