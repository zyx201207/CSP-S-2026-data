#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(n) cout << #n << " = " << n << '\n';
const int N = 2e4 + 10;
int c, n, m, d, q;
int w[2000010];

struct Node {
	int a;
	int t;
} arr[510][N]; //[线路][站台(第几个)]
int sub[500010][20]; // [站台][地铁]
int ids[500010];

bool cmp(Node x, Node y) {
	return x.a < y.a;
}

struct Node1 {
	int to;
	int w;
	int sub;
};

vector<Node1> e[N][510]; // [从哪里][线路]

int dis[500010];
bool vis[500010][510];

struct Q {
	int d;
	int u;
	int s;
	bool operator < (const Q& o) const {
		return d < o.d;
	}
};

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));

	priority_queue<Q> pq;
	// 距离，站台，线路
	dis[s] = 0;
	for (int i = 1; i <= ids[i]; i++) pq.push({arr[sub[s][i]][arr[sub[s][i]][s].a].t, s, sub[s][i]});
	while (!pq.empty()) {
		int d = pq.top().d;
		int u = pq.top().u;
		int s = pq.top().s;

		pq.pop();

		if (vis[u][s]) continue;
		vis[u][s] = true;

//		deb(d);
//		deb(u);
//		deb(s);
		for (auto it : e[u][s]) {
			int v = it.to;
			int w = it.w;
			int ss = it.sub;
			if (d + w < dis[v]) {
				dis[v] = d + w;
//				cout << "tongcheng push:" << dis[v] << ' ' << v << ' ' << ss << '\n';
				pq.push({dis[v], v, ss});
			}
		}
		for (int i = 1; i <= ids[i]; i++) {
			if (sub[u][i] == s) continue;
//			cout << "huancheng push:" << d + arr[sub[u][i]][u].t << ' ' << u << ' ' << sub[u][i] << '\n';
			pq.push({d + arr[sub[u][i]][u].t, u, sub[u][i]});
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i]; // 表示从每个地铁站的地铁口走到站厅需要的时间
	for (int i = 1; i <= n; i++) { // i号线
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> arr[i][j].a;
			cin >> arr[i][arr[i][j].a].t; // 其中 ai,j 表示第 i 条线路经过的第 j 个地铁站，
			//ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
			sub[arr[i][j].a][++ids[arr[i][j].a]] = i;
		}
		for (int j = 1; j <= k; j++) {
			for (int jj = j + 1; jj <= k; jj++) {
				e[arr[i][j].a][i].push_back({arr[i][jj].a, arr[i][arr[i][jj].a].t, i});
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int ee = 1; ee <= ids[i]; ee++) {
			e[i][0].push_back({i, arr[ee][i].t, ee});
		}
	}
	for (int i = 1; i <= m; i++) { // i站台
		for (int ss = 1; ss <= ids[i]; ss++) {
			for (int ee = 1; ee <= ids[i]; ee++) {
				if (ss == ee) continue;
				e[i][ss].push_back({i, arr[ee][i].t, ee});
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			for (auto it : e[i][j]) {
//				cout << i << ' ' << it.to << ' ' << it.w << ' '<< j <<  ' ' << it.sub << '\n';
//			}
//		}
//	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int ans = w[l] + w[r];
		dijkstra(l);
//		deb(ans);
//		deb(dis[r]);
		cout << (ans + dis[r]) << '\n';
	}
	return 0;
}
