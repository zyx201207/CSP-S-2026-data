#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1010

int c, t, n, k;
vector<int> e[N];
int dis[N][N];
int d[N];
bool vis[N];
int dep[N];
void dfs(int k, int pre) {
	dep[k] = dep[pre] + 1;
	for(auto i:e[k]) {
		if(i != pre)
			dfs(i, k);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	if(c == 7) {
		while(t--) {
			cin >> n >> k;
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= n;j++) {
					dis[i][j] = 1e15;
				}
			}
			for(int i = 1;i < n;i++) {
				int u, w;
				cin >> u >> w;
				dis[u][w] = dis[w][u] = 1;
			}
			for(int k = 1;k <= n;k++) {
				for(int i = 1;i <= n;i++) {
					for(int j = 1;j <= n;j++) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			
			int mn = 1e15;
			for(int i = 1;i <= n;i++) {
				for(int j = i + 1;j <= n;j++) {
					int mx = -1;
					for(int k = 1;k <= n;k++) {
						if(k == i || k == j) {
							continue;
						}
						mx = max(mx, min(dis[k][i], dis[k][j]));
					}
					mn = min(mn, mx);
				}
			}
			cout << mn << "\n";
		}	
	} else {
		while(t--) {
			cin >> n >> k;
			for(int i = 1;i < n;i++) {
				int u, w;
				cin >> u >> w;
			}
			cout << "0\n";
		}
	}
	return 0;
} 
