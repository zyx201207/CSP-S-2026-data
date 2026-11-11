#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 559;
struct node {
	int a, t;
};
int c, n, m, d, q, a[505][N], k[N];
ll w[N], dist[N][N], t[505][N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= m; j++){
			if (i != j) dist[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k[i]; j++){
			for (int p = j + 1; p <= k[i]; p++){
				dist[a[i][j]][a[i][p]] = dist[a[i][p]][a[i][j]] = min(dist[a[i][j]][a[i][p]], t[i][j] + t[i][p]);
			}
		}
	}
	for (int p = 1; p <= m; p++){
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= m; j++){
				dist[i][j] = min(dist[i][j], dist[i][p] + dist[p][j]);
			}
		}
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + w[x] + w[y] << endl;
	}
	return 0;
}
