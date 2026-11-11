#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 5e2 + 5;
int w[N];
long long dist[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i == j) dist[i][j] = 0;
	else dist[i][j] = INF; 
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		vector<int> a(k, 0), t(k, 0);
		for (int j = 0; j < k; j++) scanf("%d%d", &a[j], &t[j]);
		for (int j = 0; j < k; j++) {
			for (int l = j + 1; l < k; l++) if (t[j] + t[l] < dist[a[j]][a[l]]) dist[a[j]][a[l]] = dist[a[l]][a[j]] = t[j] + t[l];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i + j <= m; i++) {
			for (int k = 1; k <= m; k++) if (dist[i][k] + dist[k][i + j] < dist[i][i + j]) dist[i][i + j] = dist[i + j][i] = dist[i][k] + dist[k][i + j];
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", dist[x][y] + w[x] + w[y]);
	}
	return 0;
}
