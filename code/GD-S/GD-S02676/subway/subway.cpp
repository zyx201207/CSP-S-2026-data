#include <bits/stdc++.h>

using namespace std;

struct Node { int v; long long w; };
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 505;
const int M = 5e5 + 10;
vector<Node> g[M];
long long f[N][N];
long long ac[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C, n, m, d, q;
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> ac[i];
	for (int u = 1; u <= n; u++) {
		int ki;
		cin >> ki;
		for (int j = 1; j <= ki; j++) {
			int v;
			long long w;
			cin >> v >> w;
			g[v].push_back({u, w});
		}
	} for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			for (int k = j + 1; k < g[i].size(); k++) {
				int u = g[i][j].v;
				int v = g[i][k].v;
				long long w = g[i][j].w + g[i][k].w;
				f[u][v] = min(f[u][v], w);
				f[v][u] = min(f[v][u], w);
			}
		}
	} for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int s, t;
		cin >> s >> t;
		long long minn = INF;
		for (int i = 0; i < g[s].size(); i++) {
			for (int j = 0; j < g[t].size(); j++) {
				int u = g[s][i].v;
				int v = g[t][j].v;
				long long w = g[s][i].w + g[t][j].w;
				minn = min(minn, f[u][v] + w);
			}
		} cout << minn + ac[s] + ac[t] << '\n';
	} return 0;
}
