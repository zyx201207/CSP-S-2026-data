#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 500 + 5, M = 5e5 + 5;

struct Node {
	int to, t;
};

int n, m, d, r;
int w[M], g[N][N]; ll dis[N][N];
vector<Node> a[N];
vector<Node> c[M];
bitset<N> mk;

inline 
void dijkstra(int st) {
	priority_queue<pii, vector<pii>, greater<pii> > q;
	memset(dis[st], 0x3f, sizeof dis[st]);
	mk.reset();
	q.push(make_pair(0, st));
	dis[st][st] = 0;
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		if (mk[x]) continue;
		mk[x] = 1;
		for (int y = 1; y <= n; y ++) {
			if (g[x][y] == -1) continue;
			if (dis[st][y] > dis[st][x] + g[x][y]) dis[st][y] = dis[st][x] + g[x][y];
			q.push(make_pair(dis[st][y], y));
		}
	}
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> n >> n >> m >> d >> r;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j ++) {
			int y, z;
			cin >> y >> z;
//			a[i].push_back((Node){y, z});
			c[y].push_back((Node){i, z});
		}
	}
	memset(g, -1, sizeof g);
	for (int i = 1; i <= m; i ++) { // O(2e8)
		for (Node u : c[i]) {
			for (Node v : c[i]) {
				if (u.to == v.to) continue;
//				cout << u.to << " " << v.to << "\n";
//				Sleep(500);
				if (g[u.to][v.to] == -1 || u.t + v.t < g[u.to][v.to]) g[u.to][v.to] = g[v.to][u.to] = u.t + v.t;
			}
		}
//		cout << "\n";
	}
	for (int i = 1; i <= n; i ++) dijkstra(i);
	for (int _ = 1; _ <= r; _ ++) {
		int x, y; ll ans = 1e18;
		cin >> x >> y;
		for (Node u : c[x]) {
			for (Node v : c[y]) {
				ans = min(ans, dis[u.to][v.to] + w[x] + w[y] + u.t + v.t);
//				cout << u.to << " " << v.to << "\n";
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

