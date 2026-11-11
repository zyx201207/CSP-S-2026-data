#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10, M = 5e5 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int id, n, m, d, q, k[N];
int c[M];
//每条线路 
vector<int> a[N], t[N];
//每个点 
vector<pair<int, int>> gn[M];
//每条线路
vector<pair<int, int>> e[N];
long long dis[N][N];
priority_queue<pair<long long, int>, vector<pair<long long ,int>>, greater<pair<long long, int>>> pq;
bool vis[N];
void dijkstra(int s) {
	dis[s][s] = 0;
	pq.push({0, s});
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(pair<int, int> x : e[u]) {
			int v = x.first, w = x.second;
			if(dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				pq.push({dis[s][v], v});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> id >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 2);
		t[i].resize(k[i] + 2);
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			gn[a[i][j]].push_back({i, t[i][j]});
		}
	}
	
	for(int i = 1; i <= m; i++) {
//		cout << i << " begin:\n";
		for(int j = 0; j < (int)gn[i].size(); j++) {
			for(int k = j + 1; k < (int)gn[i].size(); k++) {
				int x = gn[i][j].first, y = gn[i][k].first, val = gn[i][j].second + gn[i][k].second;
//				cout << x << " " << y << " " << gn[i][j].second << " " << gn[i][k].second << "\n";
				e[x].push_back({y, val});
				e[y].push_back({x, val});
			}
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
		memset(vis, 0, sizeof(vis));
	}
	long long ans = 0;
//	cout << q << "\n";
	for(int i = 1; i <= q; i++) {
		int s, t; cin >> s >> t;
		ans = inf;
		//双向即s-t与t-s一样 
		//s与t可以属于同一条路线 
		for(int j = 0; j < (int)gn[s].size(); j++) {
			for(int k = 0; k < (int)gn[t].size(); k++) {
				int x = gn[s][j].first, y = gn[t][k].first, val = gn[s][j].second + gn[t][k].second;
//				cout << x << " " << y << " " << dis[x][y] << " " << val << "\n";
				long long res = dis[x][y] + val;
				ans = min(ans, res);
			}
		} 
		ans += c[s] + c[t]; //2e9int
		cout << ans << "\n";
	}
	/* */
	return 0;
} 
/*
若想转战与t为同一个点，当前线路并非最优 
*/
