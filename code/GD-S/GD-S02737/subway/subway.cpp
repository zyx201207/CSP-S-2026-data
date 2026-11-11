#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int MAXN = 505, MAXM = 405;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct Edge{
	int v;
	ll w;
};
int w[MAXM], n, m, c, d, q;
vector<Edge> e[MAXM];
ll dis[MAXM + MAXN][MAXM + MAXN];
void add_edge(int u, int v, ll w){
	e[u].push_back({v, w});
	e[v].push_back({u, w});
	dis[u][v] = w;
	dis[v][u] = w;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n + m; i++){
		for(int j = 1; j <= n + m; j++){
			if(i != j) dis[i][j] = inf;
		}
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			add_edge(a, i + m, t);
		}
	}
	for(int k = 1; k <= n + m; k++){
		for(int i = 1; i <= n + m; i++){
			for(int j = 1; j <= n + m; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << '\n';
	}
//	for(int i = 1; i <= n + m; i++){
//		for(int j = 1; j <= n + m; j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	return 0;
}
