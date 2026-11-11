#include <bits/stdc++.h>
using namespace std;

#define ll long long

int c, n, m, d, q;

const int M = 500000, N = 500, D = 21;
int w[M + 1];
int tt[M + 1][N + 1];
ll dis[N + 1][N + 1];

int v[M + 1][D + 1];
int sz[M + 1];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	
	for (int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++){
			int a, t;
			scanf("%d %d", &a, &t);
			v[a][++sz[a]] = i;
			tt[a][i] = t;
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = LLONG_MAX / 2;
		}
		dis[i][i] = 0;
	}
	
	for (int i = 1; i <= m; i++){
		for (int idx1 = 1; idx1 <= sz[i]; idx1++){
			int x = v[i][idx1];
			for (int idx2 = 1; idx2 <= sz[i]; idx2++){
				int y = v[i][idx2];
				if (x == y) continue;
				// tt[i][x] + tt[i][y]
				dis[x][y] = min(dis[x][y], (ll)tt[i][x] + tt[i][y]);
			}
		}
	}
	
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	
	while (q--){
		int x, y;
		scanf("%d %d", &x, &y);
		ll res = LLONG_MAX / 2;
		for (int idx1 = 1; idx1 <= sz[x]; idx1++){
			int i = v[x][idx1];
			for (int idx2 = 1; idx2 <= sz[y]; idx2++){
				int j = v[y][idx2];
				if (dis[i][j] == LLONG_MAX / 2) continue;
				res = min(res, dis[i][j] + w[x] + w[y] + tt[x][i] + tt[y][j]);
			}
		}
		printf("%lld\n", res);
	}
	
	
	return 0;
}
