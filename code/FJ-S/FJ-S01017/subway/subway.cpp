#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
using namespace std;
const int N = 1000010;
const int inf = 1e18;
int c, n, m, d, q;
int dis[550][550];
bool vis[510][20010], viss[550];
int g[550][550];
int a[510][20010], t[510][20010], w[N];
int k[550];
void dijstra(int s) {
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, s});
	memset(viss, 0, sizeof(viss));
	fill(dis[s], dis[s] + 510, inf);
	dis[s][s] = 0;
	while (!heap.empty()) {
		auto [hhh, u] = heap.top();
		heap.pop();
		if(viss[u]) continue;
		viss[u] = 1;
		For(v, 1, n) {
			if(v == u) continue;
			if(dis[s][u] + g[u][v] < dis[s][v]) {
				dis[s][v] = dis[s][u] + g[u][v];
				heap.push({dis[s][v], v});
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	For(i, 1, m) cin >> w[i];
	memset(t, 0x3f, sizeof(t));
	For(i, 1, n) {
		cin >> k[i];
		For(j, 1, k[i]) {
			cin >> a[i][j] >> t[i][a[i][j]];
			vis[i][a[i][j]] = 1;
		}
	}
	memset(g, 0x3f, sizeof(g));
	For(i, 1, n) {
		For(j, 1, n) {
			if(i == j) continue;
			For(w, 1, k[i]) {
				if(t[i][a[i][w]] <= 1000000000 && t[j][a[i][w]] <= 1000000000) {
					g[i][j] = min(g[i][j], t[i][a[i][w]] + t[j][a[i][w]]);
				}
			}
		}
	}
//	For(i, 1, n) For(j, 1, k[i]) cout << i <<' '<<j <<' '<< t[i][a[i][j]] <<'\n';
	For(i, 1, n) {
		dijstra(i); 
	}
//	For(i, 1, n) For(j, 1, n) cout << i<< " " << j <<' ' << dis[i][j] << '\n'; 
	while (q --) {
		int x, y;
		cin >> x >> y;
		vector<int> xr, yr; 
		For(i, 1, n) {
			if(vis[i][x]) {
//				cout <<"hh\n";
				xr.push_back(i);	
			}
			if(vis[i][y]) {
//				cout <<"hh\n";
				yr.push_back(i);
			}
		}
		int ans = inf;
		For(i, 0, xr.size() - 1) {
			For(j, 0, yr.size() - 1) {
				ans = min(ans, dis[xr[i]][yr[j]] + t[xr[i]][x] + t[yr[j]][y]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
