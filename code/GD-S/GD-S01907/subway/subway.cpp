#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N = 510, M = 5e5 + 10;
ll c, n, m, d, q;
ll w[M];
vector<pair<ll, ll> > e[N];
ll dis[N];
bool vis[N];

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;
	q.push({0, s});
	while(!q.empty()) {
		auto t = q.top(); q.pop();
		int u = t.second;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto ed : e[u]) {
			int v = ed.first, w = ed.second;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
		
	} 
}


signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m;i++) {
		cin >> w[i]; 
	}
	for(int i = 1; i <= n;i++) {
		ll k;
		cin >> k;
		vector<pair<ll, ll > > vt;
		for(int j = 1; j <= k;j++) {
			ll a, t;
			cin >> a >> t;
			vt.push_back({a, t});
		}
//		for(int i = 0; i < k;i++) {
//			for(int j = 0; j < k;j++) {
//				if(i == j) continue;
//				e[i].push_back({j, 0});
//			}
//		}
//		for(int i  = 0; i < k;i++) {
//			 
//		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		if(x == y ) {
			cout << 0 << '\n';
			continue;
		} 
//		dijkstra(x);
		cout << w[x] + w[y] + 1 << '\n';
	}
	return 0;
} 
