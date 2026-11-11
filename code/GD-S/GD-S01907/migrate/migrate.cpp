#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N = 2e6 + 10;

int x[N];

vector<pair<ll, ll> > e[N];
ll dis[N];
bool vis[N];
ll cnt[N];

void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;
	q.push({0, s});
	cnt[s] = 1;
	while(!q.empty()) {
		auto t = q.top(); q.pop();
		int u = t.second;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto ed : e[u]) {
			int v = ed.first, w = ed.second;
			if(dis[v] == dis[u] + w) {
				cnt[v] += cnt[u];
			}
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u];
				q.push({dis[v], v});
			}
//			cout << "u : " << u << " v : " << v << " dis : " << dis[v] << " cnt : " << cnt[v] << '\n';
		}
	} 
}

void solve() {
	int n, d;
	cin >> n >> d;
	for(int i = 1;i <= n;i++) {
		e[i].clear();
	}
	for(int i = 1;i <= n;i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= n;i++) {
		for(int j = i + 1; j <= n;j++) {
			if(i == j) continue;
			if(abs(x[i] - x[j]) <= d) {
				e[i].push_back({j, 1});
				e[j].push_back({i, 1});
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		dijkstra(i);
		for(int j = i + 1;j <= n;j++) {
			if(i == j) continue;
			if(cnt[j] == 2) { 
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
