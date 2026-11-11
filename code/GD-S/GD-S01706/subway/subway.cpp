#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 5e5+10;
int c, n, m, d, q, w[M];
int k[N], dis[N][N];
struct edge{
	int u, d;
};
vector<edge> sub[N];
vector<edge> g[M];
void F(){
	for(int i=1;i<=n;i++) dis[i][i] = 0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
void solve(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		for(auto x:sub[i]){
			for(edge to:g[x.u]){
				int v = to.u;
				dis[i][v] = dis[v][i] = min(dis[v][i],x.d+to.d);
			}
		}
	}F();
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int x, t; cin >> x >> t;
			sub[i].push_back({x,t});
			g[x].push_back({i,t});
		}
	}solve();
	while(q--){
		int x, y; cin >> x >> y;
		int res = 1e18;
		for(auto s:g[x]){
			for(auto t:g[y]){
				res = min(res, dis[s.u][t.u]+s.d+t.d);
			}
		}
		cout << res + w[x] + w[y] << '\n';
	}
	return 0;
}
