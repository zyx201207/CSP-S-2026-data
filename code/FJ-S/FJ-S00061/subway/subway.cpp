#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k[505], a[500005], t[500005], dis[500005], g[10005][10005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 1; i <= m; i++) cin>>w[i];
	if (7 <= c && c <= 11) {
		memset(g, 0x3f, sizeof(g));
		for (int i = 1; i <= m; i++) g[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			cin>>k[i];
			for (int j = 1; j <= k[i]; j++) cin>>a[j]>>t[j];
			for (int j = 1; j < k[i]; j++) {
				g[a[j]][a[j+1]] = g[a[j+1]][a[j]] = t[j] + t[j+1];
			}
		}
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= m; j++) {
//				cout<<g[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		while (q--) {
			int x, y;
			cin>>x>>y;
			cout<<w[x] + w[y] + g[x][y]<<'\n';
		}
		return 0;
	}
	if (d == 1) {
		for (int i = 1; i <= n; i++) {
			cin>>k[i];
			int t;
			for (int j = 1; j <= k[i]; j++) cin>>t>>t;
		}
		while (q--) {
			int x, y;
			cin>>x>>y;
			cout<<w[x] + w[y]<<'\n';
		}
		return 0;
	}
	return 0;
}
