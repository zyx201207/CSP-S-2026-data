#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;

int n, dist[N], cnt[N], ans;
bool vis[N];

ll d, x[N];
vector<int> g[N];

void bfs(int s) {
	
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x3f, sizeof(dist));
	
	queue<int> qu;
	
	qu.push(s);
	dist[s] = 0;
	cnt[s] = 1;
	
	while (!qu.empty()) {
		
		int u = qu.front();
		qu.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (auto v : g[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				cnt[v] = cnt[u];
				qu.push(v);
			}
			else if (dist[v] == dist[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
}
void init() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
}
void solve() {
	cin >> n >> d;
	init();
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		int id = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		for (int j = i + 1; j <= id; j++) {
			g[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
		
		for (int j = i + 1; j <= n; j++) {
			if (cnt[j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}
int main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	 
}
