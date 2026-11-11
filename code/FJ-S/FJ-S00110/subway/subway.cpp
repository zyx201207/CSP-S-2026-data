#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

ll w[20005];
ll a[505][20005];
ll t[505][20005];
bool vis[20505];
ll dis[20505];
ll k[505];

struct Edge {
	ll v, w;
};

vector<Edge> g[500505];

bool operator<(Edge l, Edge r) {
	return l.w > r.w;
}

ll c, n, m, d, q;

void init() {
	for (ll i = 1 ; i <= n ; i ++) {
		for (ll j = 1 ; j <= k[i] ; j ++) {
			g[i].push_back({a[i][j]+n, t[i][j]});
			g[a[i][j]+n].push_back({i, t[i][j]});
		}
	}
}

ll qq(ll x, ll y) {
	priority_queue<Edge> pq;
	pq.push({x, 0});
	for (ll i = 1 ; i <= n+m ; i ++) {
		dis[i] = LLONG_MAX;
		vis[i] = false;
	}
	dis[x] = 0;
	while (!pq.empty()) {
		Edge s = pq.top();
		pq.pop();
		if (vis[s.v]) continue;
		vis[s.v] = true;
		//printf("[D] %lld, %lld\n", s.v, s.w);
		if (s.v == y) return s.w;
		for (Edge e : g[s.v]) {
			//printf("[D] . %lld, %lld\n", e.v, e.w);
			if (dis[e.v] > s.w + e.w) {
				//printf("[D] . . TAKE\n");
				dis[e.v] = s.w + e.w;
				pq.push({e.v, dis[e.v]});
			}
		}
	}
	return dis[y];
}

void work1() {
	for (ll i = 1 ; i <= m ; i ++) {
		scanf("%lld", &w[i]);
	}
	for (ll i = 1 ; i <= n ; i ++) {
		scanf("%lld", &k[i]);
		for (ll j = 1 ; j <= k[i] ; j ++) {
			scanf("%lld%lld", &a[i][j], &t[i][j]);
		}
	}
	init();
	for (ll i = 1 ; i <= q ; i ++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll ans = w[x] + w[y];
		x+=n;y+=n;
		//printf("[D] + %lld", ans);
		printf("%lld\n", ans + qq(x, y));
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	if (m <= 20005) work1();
	else work1();
	return 0;
}
