#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e3 + 10, INF = 0x3f3f3f3f;

int t;
int idx = 1;
int n, d;
int elast[N];
int dist[N][N];

struct Edge {
	int u, v, w;
	int next;
} edge[N << 2];

strcut PQnode {
	int dis, i;
	PQnode(int _dis = 0, int _i = 0) {
		dis = _dis; i = _i;
	}
	bool operator < (const PQnode &w) const {
		return dis < w.dis;
	}
};

void add(int u, int v, int w) {
	edge[idx].v = v;
	edge[idx].w = w;
	edge[idx].next = elast[u];
	elast[u] = idx ++ ;
}

void solve() {
	cin >> n >> d;
	vector<int> x(n + 1, 0);
	memset(dist, INF, sizeof dist);
	for (int i = 0; i <= idx; i ++ ) edge[idx].u = 0, edge[idx].v = 0, edge[idx].next = 0; idx = 1;
	for (int i = 0; i < N; i ++ ) elast[i] = 0;
	for (int i = 1; i <= n; i ++ ) cin >> x[i];
	vector<int> order;
	vector<int> bulk(n + 1, INF);
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ ) {
			if (abs(x[i] - x[j]) <= d) {
				dist[i][j] = dist[j][i] = 1;
			}
		}
	}
	vector<vector<int>> mark(n + 1, vector<int>(n + 1, 0));
	for (int k = 1; k <= n; k ++ ) {
		for (int i = 1; i <= n && i != k; i ++ ) {
			for (int j = 1; j <= n && i != j && i != k; j ++ ) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					mark[i][k] ++ ; mark[k][j] ++ ;
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ ) {
			if (mark[i][j] == 2) ans ++ ;
		}
	}
	
	cout << ans << "\n";
}

int main(int argc, char *argv[]) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> t;
	
	while (t -- ) solve();
	
	return 0;
}
