#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 5e5 + 5;
int w[N];
vector<pii> can[N];
int dis[505][505];
int c, n, m, d, q;
vector<int> me[N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout << "pass";
	cin >> c >> m >> n >> d >> q;
	for(int i = 1; i <= n; i++) {
		 cin >> w[i];
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		for(int j = 1 ; j <= num; j++) {
			int x, y;
			cin >> x >> y;
			can[x].push_back({i, y});
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 0; i < can[k].size(); i++) {
			int u = can[k][i].first;
			int w1 = can[k][i].second;
			for(int j = 0; j < can[k].size(); j++) {
				int v = can[k][j].first;
				int w2 = can[k][j].second;
				if(u == v) {
					dis[u][v] = 0;
					continue;
				}
				dis[u][v] = min(dis[u][v], w1 + w2);
			}
		}
			
	}
	for(int k = 1; k <= m; k++) {
		for(int i = 1; i <= m; i++) {
			if(dis[i][k] >= 1e18) continue;
			for(int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		int st, ed;
		cin >> st >> ed;
		int ans = 1e18;
		for(int i = 0; i < can[st].size(); i++) {
			int u = can[st][i].first;
			int w1 = can[st][i].second;
			for(int j = 0; j < can[ed].size(); j++) {
				int v = can[ed][j].first;
				int w2 = can[ed][j].second;
				ans = min(ans, dis[u][v] + w1 + w2);
			}
		}
		ans += w[st];
		ans += w[ed];
		cout << ans << '\n';
	} 
}
