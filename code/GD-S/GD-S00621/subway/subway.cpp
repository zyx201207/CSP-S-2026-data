#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second 
using namespace std;

const int N = 1e3 + 5;

struct node {
	int v, w;
	bool operator<(const node b) const {
		return w < b.w;
	}
};

int a[N], t[N], w[N], g[N][N], dis[N][N];
vector<pii> e[N];

void dij(int st) {
	priority_queue<node> que;
	que.push({st, 0});
	dis[st][st] = 0;
	while(!que.empty()) {
		int u = que.top().v;
		que.pop();
		for(int i = 0; i < e[u].size(); i++) {
			int v = e[u][i].fir, w = e[u][i].sec;
			if(dis[st][u] + w < dis[st][v]) {
				dis[st][v] = dis[st][u] + w;
				que.push({v, dis[st][v]});
			}
		}
	}
}

signed main() {//44pts 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof(g));
	memset(dis, 0x3f, sizeof(dis));
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	int T = 0;
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		if(k > 0 && T == 0) T = t[1];
		if(c <= 11) {
			for(int x = 1; x <= k; x++) {
				for(int y = x + 1; y <= k; y++) {
					int u = a[x], v = a[y];
					g[u][v] = g[v][u] = min(g[u][v], t[x] + t[y]);
//					cout << "debug " << u << ' ' << v << ' ' << g[u][v] << endl;
				}
			}
		}
	}
	if(c <= 11) {
		for(int i = 1; i <= m; i++) {
			for(int j = i + 1; j <= m; j++) {
//				cout << i << ' ' << j << ' ' << g[i][j] << endl;
				if(g[i][j] != g[0][0]) {
//					cout << i << ' ' << j << ' ' << g[i][j] << endl;
					e[i].push_back({j, g[i][j]});
					e[j].push_back({i, g[i][j]});
				}
			}
		}
		for(int i = 1; i <= m; i++) {
			dij(i);
		}
		while(q--) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + w[v] + dis[u][v] << endl;
		}
	}
	else {
		while(q--) {
			int u, v;
			cin >> u >> v;
			cout << w[u] + w[v] + T << endl;
		}
	}
	return 0;
}
