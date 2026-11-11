#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, M = 5e5 + 5, D = 25;
int w[M];

int head[M + N], ver[D * M * 2], Next[D * M * 2], edge[D * M * 2];
int tot;
int dist[M + N];
bool vis[M + N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, n, m, d, q, ki, x, y;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> ki;
		for(int j = 1; j <= ki; j++) {
			cin >> x >> y;
			add(i + m, x, y);
			add(x, i + m, y);
		}
	}
	while(q--) {
		cin >> x >> y;
		memset(dist, 0x3f, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		dist[x] = 0;
		vis[x] = 1;
		priority_queue< pair<int, int> > q;
		q.push(make_pair(-dist[x], x));
		while(!q.empty()) {
			int u = q.top().second, l = -q.top().first; q.pop();
			if(l != dist[u]) continue;
			for(int i = head[u]; i; i = Next[i]) {
				int v = ver[i];
				if(dist[v] > dist[u] + edge[i]) {
					dist[v] = dist[u] + edge[i];
					q.push(make_pair(-dist[v], v));
				}
			}
		}
		cout << dist[y] + w[x] + w[y] << endl;
	}
	return 0;
}

