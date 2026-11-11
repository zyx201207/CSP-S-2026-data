#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,dd,q; 
int w[500005],num[505];
vector <pair<int,int> > rte[500005];
int dis[505][505];
// m:点数
// n:路线数 


signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		for (int j = 1; j <= num[i]; j++) {
			int x,y;
			cin >> x >> y;
			rte[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < rte[i].size(); j++) {
			for (int k = j + 1; k < rte[i].size(); k++) {
				int u = rte[i][j].first,v = rte[i][k].first;
				int d = rte[i][j].second + rte[i][k].second;
				dis[u][v] = min(dis[u][v],d);
				dis[v][u] = dis[u][v];
			}
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int st,en;
		cin >> st >> en;
		int res = 1e18;
		for (int i = 0; i < rte[st].size(); i++) {
			for (int j = 0; j < rte[en].size(); j++) {
				pair<int,int> u = rte[st][i],v = rte[en][j];
				res = min(res,dis[u.first][v.first] + u.second + v.second);
			}
		}
		cout << res + w[st] + w[en] << "\n";
	}
	return 0;
}
