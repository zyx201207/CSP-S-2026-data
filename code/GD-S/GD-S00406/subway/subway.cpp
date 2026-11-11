#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 5e5+10;
const ll inf = 2e18;
ll w[maxm];

vector<pair<int, int> > adj[maxm * 2];
int nodecnt = 0;

vector<ll> dist[1005];
vector<ll> dst;

void dijsktra(int id) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[id].resize(nodecnt + 1, inf);
	dist[id][id] = 0;
	pq.push({0, id});
	while(!pq.empty()) {
		ll c = pq.top().first, u = pq.top().second;
		pq.pop();
		if(c > dist[id][u]) continue;
		for(pair<int, int> tmp : adj[u]) {
			int v = tmp.first;
			ll cost = (ll)tmp.second;
			if(dist[id][v] > c + cost) {
				dist[id][v] = c + cost;
				pq.push({dist[id][v], v});
			}
		}
	}
}

void bfs(int id, int tar) {
	dst.clear();
	dst.resize(nodecnt + 1, inf);
	deque <pair<ll, int>> q;
	q.push_front({0, id});
	dst[id] = 0;
	while(!q.empty()) {
		ll c = q.front().first; int u = q.front().second;
		q.pop_front();
		if(c > dst[u]) continue;
		if(u == tar) return ;
		for(pair<int, int> tmp : adj[u]) {
			int v = tmp.first; ll cost = (ll)tmp.second;
			if(dst[v] > cost + c) {
				dst[v] = cost + c;
				if(cost == 0LL) q.push_front({dst[v], v});
				else q.push_back({dst[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	nodecnt = m + 1;
	for(int i = 1; i <= n; i++) {
		int ki; cin >> ki;
		int a, t; cin >> a >> t;
		int id = nodecnt++;
		adj[id].push_back({a, t});
		adj[a].push_back({id, t});
		for(int j = 2; j <= ki; j++) {
			cin >> a >> t;
			id = nodecnt;
			adj[id].push_back({a, t});
			adj[a].push_back({id, t});
			adj[id].push_back({nodecnt - 1, 0});
			adj[nodecnt - 1].push_back({id, 0});
			nodecnt++;
		}
	}
	
	if(c <= 11) {
		for(int i = 1; i <= m; i++) dijsktra(i);
		while(q--) {
			int x, y; cin >> x >> y;
			ll ans = dist[x][y] + w[x] + w[y];
			cout << ans << "\n";
		}		
		return 0;
	} else if(12 <= c <= 19) {
		while(q--) {
			int x, y; cin >> x >> y;
			bfs(x, y);
			ll ans = dst[y] + w[x] + w[y];
			cout << ans << "\n";
		}
	}
	return 0;
}
