#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pii pair<int,int>
#define ll long long
const int N = 505,M = 5e5+5;
const ll inf = 9e18;
int c,n,m,d,q,val[M];
vector<pii> g[M];
ll dis[N][N];
void flord(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j) continue;
			for(int k = 1;k<=n;k++){
				if(j==k||i==k) continue;
				if(dis[i][k]==0||dis[k][j]==0) continue;
				if(dis[i][j]==0) dis[i][j] = inf;
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void update(int idx){
	for(int i = 0;i<g[idx].size();i++){
		for(int j = i+1;j<g[idx].size();j++){
			int u = g[idx][i].first-n,v = g[idx][j].first-n,w = g[idx][i].second+g[idx][j].second;
			if(dis[u][v]==0) dis[u][v] = inf;
			dis[u][v] = min(dis[u][v],(ll)w);
			if(dis[v][u]==0) dis[v][u] = inf;
			dis[v][u] = min(dis[v][u],(ll)w);
		}
	}
}
signed main(){
	fre("subway");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> val[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin >> k;
		for(int j = 1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			g[a].push_back({i+n,t});
		}
	}
	for(int i = 1;i<=m;i++) update(i);
	flord();
	while(q--){
		int u,v;
		cin >> u >> v;
		ll ans = inf;
		for(int i = 0;i<g[u].size();i++){
			for(int j = 0;j<g[v].size();j++){
				int x = g[u][i].first-n,y = g[v][j].first-n;
				if(x==y) ans = min(ans,(ll)g[u][i].second+g[v][j].second);
				else ans = min(ans,g[u][i].second+g[v][j].second+dis[x][y]);
			}
		}
		cout << ans+val[u]+val[v] << '\n';
	}
	return 0;
}
