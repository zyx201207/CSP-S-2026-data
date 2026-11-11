#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 5,M = 5e5 + 5,inf = 2e18;
int c,n,m,D,q,w[M],d[N][N];
vector<pair<int,int> >g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(d,0x3f,sizeof(d));
	cin >> c >> n >> m >> D >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		d[i][i] = 0;
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int x,t;
			cin >> x >> t;
			g[x].push_back({i,t});
		}
	}
	for (int i = 1;i <= m;i++){
		for (auto x : g[i]){
			for (auto y : g[i]){
				int u = x.first,v = y.first;
				if (u != v){
					int val = min(d[u][v],x.second + y.second);
					d[u][v] = d[v][u] = val;
				} 
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		int val = w[x] + w[y];
		int ans = inf;
		for (auto i : g[x]){
			for (auto j : g[y]){
				ans = min(ans,val+i.second+j.second+d[i.first][j.first]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}




