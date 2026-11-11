#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define D(a) cout << #a << " : " << a << " "
#define nl cout << "\n"
const int N = 510,M = 5e5 + 10;
int c,n,m,d,q;
vector<pii>g[M];
int w[M];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		int k; cin >> k;
		for (int j=1;j<=k;j++){
			int a,t; cin >> a >> t; g[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for (int i=1;i<=n;i++) dis[i][i] = 0;
	for (int i=1;i<=m;i++){
		for (int j=0;j<g[i].size();j++){
			for (int k=j+1;k<g[i].size();k++){
				dis[g[i][j].first][g[i][k].first] = min(g[i][j].second + g[i][k].second,dis[g[i][j].first][g[i][k].first]);
				dis[g[i][k].first][g[i][j].first] = min(g[i][j].second + g[i][k].second,dis[g[i][k].first][g[i][j].first]);
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--){
		int x,y; cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (int i=0;i<g[x].size();i++){
			for (int j=0;j<g[y].size();j++){
				ans = min(ans,dis[g[x][i].first][g[y][j].first]+w[x]+w[y]+g[x][i].second+g[y][j].second);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
