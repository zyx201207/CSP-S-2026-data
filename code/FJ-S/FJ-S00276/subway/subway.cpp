#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const int N = 505, M = 5e5 + 5, D = 25;
int id, n, m, d, q;
long long w[M];
int c[M], a[M][D];
long long b[M][D], dist[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("subway")
	int l, u, v;
	long long x;
	cin >> id >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> l;
		for (int j = 1; j <= l; j++){
			cin >> u >> x;
			c[u]++;
			a[u][c[u]] = i;
			b[u][c[u]] = x;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			dist[i][j] = dist[j][i] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= c[i]; j++){
			for (int k = 1; k <= c[i]; k++){
				if (j == k){
					continue;
				}
				dist[a[i][j]][a[i][k]] = min(dist[a[i][j]][a[i][k]], b[i][j] + b[i][k]);
			}
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--){
		cin >> u >> v;
		long long res = 1e18;
		for (int i = 1; i <= c[u]; i++){
			for (int j = 1; j <= c[v]; j++){
				res = min(res, b[u][i] + dist[a[u][i]][a[v][j]] + b[v][j]);
			}
		}
		cout << w[u] + res + w[v] << "\n";
	}
	return 0;
}

