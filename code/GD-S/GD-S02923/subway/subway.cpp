#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 500+5, M = 2e4+5, D = 20+5;
int c, n, m, d, q;//n 线路数 m 地铁站数 
int w[M], k[N], a[N][M], t[N][M], to[M][N];
long long dis[N][N];
vector <int> man[M];

void init(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dis[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i++){
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k[i]; j++){
			int id = a[i][j];
			to[id][i] = t[i][j];
		}
	}
	for (int i = 1; i <= m; i++){
		for (int x = 1; x <= n; x++){
			for (int y = 1; y <= n; y++){
				if (x == y) continue;
				if (to[i][x] != 0 && to[i][y] != 0){
					dis[y][x] = dis[x][y] = min(dis[y][x], min(dis[x][y], 1ll*to[i][x]+to[i][y]));
				}
			}
		}
	}
}

void solve(){
	init();
	for (int u = 1; u <= n; u++){
		for (int v = 1; v <= n; v++){
			for (int k = 1; k <= n; k++){
				dis[v][u] = dis[u][v] = min(dis[v][u], min(dis[u][v], dis[u][k]+dis[k][u]));
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			man[a[i][j]].push_back(i);
		}
	}
	
	solve();
	
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		int kx, ky;
		for (int u = 0; u < man[x].size(); u++){
			for (int v = 0; v < man[y].size(); v++){
				if (ans >= dis[man[x][u]][man[y][v]]){
					kx = man[x][u];
					ky = man[y][v];
					ans = dis[kx][ky];
				}
			}
		}
		cout << w[x] + to[x][kx] + ans + to[y][ky] + w[y] << "\n";
	}
	return 0;
}
