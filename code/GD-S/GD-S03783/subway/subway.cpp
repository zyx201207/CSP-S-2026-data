#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-x))
#define MID(l, r) ((l) + ((r) - (l)) >> 1)
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using lf = double;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 510, M = 1010;

int c, n, m, d, q;
int w[M], a[N][M], t[N][M], dis[N][N], ans[N][N];
vector<int> bel[M];

struct Edge {
	int nxt, to;
} g[M << 1];
int h[M], cnt;
void Add(int u, int v) {
	g[++cnt] = {h[u], v};
	h[u] = cnt;	
} 

void Input() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; +=i) {
		cin >> w[i]; 
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; ++j) {
			cin >> a[i][j] >> t[i][j];
			bel[a[i][j]].push_back(i);
		} 
	}
}




void Dijk(int s, int dist[]) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> vis(m);
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int p = pq.top().se;
		pq.pop();
		if (vis[p]) {
			continue;
		}
		vis[p] = 1;
		for (int i = h[p]; i; g[i].nxt) {
			int to = g[i].to;
			if (dist[p] + 1 >= dist[to]) {
				continue;
			}
			dist[to] = dist[p] + 1;
			pq.push({dis[to], to});
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Input();
	Init();
	
	
	return 0;
}

