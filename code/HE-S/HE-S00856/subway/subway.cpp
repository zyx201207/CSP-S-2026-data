#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,D,q,W[500010],d[505][505]; vector<array<int,2> > g[500010];
signed main() {
	freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> W[i];
	memset(d,0x3f,sizeof(d)); for(int i = 1; i <= n; i++) {
		d[i][i] = 0;
		int k; cin >> k; while(k--) {
			int a,t; cin >> a >> t; g[a].push_back({i,t});
		}
	}
	for(int i = 1; i <= m; i++) {
		int k = g[i].size();
		for(int x = 0; x < k; x++) {
			for(int y = x+1; y < k; y++) {
				int u = g[i][x][0],v = g[i][y][0],c = g[i][x][1]+g[i][y][1];
				d[v][u] = d[u][v] = min(d[u][v],c);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	while(q--) {
		int u,v,ans = 0x3f3f3f3f3f3f3f3f; cin >> u >> v;
		for(auto x:g[u]) for(auto y:g[v]) {
			ans = min(ans,d[x[0]][y[0]]+x[1]+y[1]);
		} printf("%lld\n",ans+W[u]+W[v]);
	}
	return 0;
}
