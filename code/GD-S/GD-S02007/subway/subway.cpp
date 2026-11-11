#include<bits/stdc++.h>
using namespace std;
#define int long long //注意内存

//c++14
//多测清空
//边界
//复杂度

const int N = 205;
const int M = 405;

int w[M];
int a[M][M], t[M][M];

struct Edge {
	int v, w;
};
vector<Edge> e[M * N];
int dis[M * N];
bool vis[N * M];

void dijkstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int d = q.top().first, u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(auto& E : e[u]) {
			int v = E.v, W = E.w;
			if(dis[v] > d+ W) {
				dis[v] = d + W;
				q.push({dis[v], v});
			}
		}
	}
}

void ae(int u, int v, int W) {
	e[u].push_back({v, W});
	e[v].push_back({u, W});
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int C, n, m, d, q;                      
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int ki;
		cin >> ki;
		for(int j = 1; j <= ki; j++) {
			cin >> a[i][j] >> t[i][j];
			if(j != 1)
				ae(a[i][j] + i * m, a[i][j - 1] + i * m, 0);
			ae(a[i][j], i * m + a[i][j], t[i][j]);
		}
	}
	while(q--) {
		int xi, yi;
		cin >> xi >> yi;
		dijkstra(xi);
		cout << dis[yi] + w[xi] + w[yi] << "\n";
	}
	
	return 0;
}
//I AK IOI

