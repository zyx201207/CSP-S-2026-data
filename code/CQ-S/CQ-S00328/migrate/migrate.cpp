#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 5e3 + 5;
int c, t, n, d;
int val[N];
int dp[N];
int dis[N];
bool vis[N];
int a[N];
vector<int> e[N];
void dijkstra(int st) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[st] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, st});
	while(q.size()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < e[u].size(); i++) {
			int v = e[u][i];
			int w = 1;
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				dp[v] = dp[u];
				q.push({dis[v], v});
			}
			else if(dis[u] + w == dis[v]) {
				dp[v] += dp[u];
			}
		} 
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[j] - a[i]) <= d) {
					e[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			memset(dp, 0, sizeof(dp));
			dp[i] = 1;
			dijkstra(i);
//			if(i == 1) cout << dis[3] << '\n'; 
			for(int j = i + 1; j <= n; j++) {
//				cout << dp[j] << '\n';
				if(dp[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) e[i].clear();
	}
}
