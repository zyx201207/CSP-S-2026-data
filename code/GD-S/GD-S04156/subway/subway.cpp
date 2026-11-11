#include <iostream>
#include <cstring>
using namespace std;

const int N = 505, M = 5e5 + 5, K = 1e5 + 5;
int dis[N][N], w[M];
int c, n, m, d, q;
int k[N];
struct Node {
	int a, t;
}a[N][K];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
			cin >> a[i][j].a >> a[i][j].t;
	}
	memset(dis, 0x3f, sizeof dis);
	for(int l = 1; l <= n; l++) {
		for(int i = 1; i <= k[l]; i++) {
			for(int j = i; j <= k[l]; j++) {
				int u = a[l][i].a, v = a[l][j].a;
				int t1 = a[l][i].t, t2 = a[l][j].t;
				if(i == j) dis[u][v] = dis[v][u] = 0;
				else dis[u][v] = dis[v][u] = t1 + t2;
			}
		}
	}
	for(int k = 1; k <= m; k++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << '\n';
	}
}
