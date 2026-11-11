#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
int reach[N]; // reach[i]表示第i只鸟最远能到达的岛屿
ll x[N], pre[N];
int c, t; 
int n;
ll d;
ll ans = 0;
vector<int> g[N];
int dist[N][N];
int cnt[N][N];
void dijstra(int s) {
	priority_queue<pair<int, int> > pq;
	pq.push({0, s});
	dist[s][s] = 0;
	while (!pq.empty()) {
		int mindis = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (mindis != dist[s][u]) continue;
		
		for (int v : g[u]) {
			if (dist[s][v] >= dist[s][u] + 1) {
				if (dist[s][v] > dist[s][u] + 1) {
					cnt[s][v] = 1;
					dist[s][v] = dist[s][u] + 1;
					pq.push({dist[s][v], v}); 
				}
				else {
					cnt[s][v]++;
				}
			}
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			g[i].clear(); 
		}
		for (int l = 1, r = 1; l <= n; l++) {
			while (x[r + 1] - x[l] <= d && r + 1 <= n) r++;
			reach[l] = r;
			for (int i = l + 1; i <= r; i++) {
				g[l].push_back(i);
				g[i].push_back(l);
			}
		}
//		for (int i = 1; i <= n; i++) {
//			cout << "reach[" << i << "] = " << reach[i] << '\n';
//		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = 5005;
				cnt[i][j] = 0;
			}
			dijstra(i);
			for (int j = 1; j <= n; j++) {
				if (cnt[i][j] == 2) {
//					cout << i << " " << j << "\n";
//					cout << "mindis=" << dist[i][j] << "\n";
					ans++;
				}
			}	
		}	
		cout << ans / 2 << "\n";
	}
	return 0;
}
