#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
vector<int> g[N];
long long dis[N][N], vis[N][N];
long long n;
long long d;
long long x[N];
//void bfs(int s) {
//	queue<int> q;
//	q.push(s);
//	vis[s][s] = 1;
//	while(!q.empty()) {
//		int u = q.front();
//		q.pop();
//		if(vis[s][u] > 1) continue;
////		cout << u << ' ';
//		for(auto v : g[u]) {
//			if(vis[s][v]) vis[s][v] += vis[s][u];
//			else {
//				vis[s][v] = vis[s][u];
//				dis[s][v] = dis[s][u] + 1;
//				q.push(v);
//			}
//		}
//	}
//}
long long ans;
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j >= 1; j--) {
			if(x[i] - x[j] > d) break;
			g[j].push_back(i); 
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(auto v : g[i]) dis[i][v] = 1, vis[i][v] = 1;
//		cout << endl;
	}
//	for(int i = 1; i <= n; i ++) {
//		bfs(i);
////		cout << endl;
//	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= k; i++) {
			if(vis[i][k] > 2) continue; 
			for(int j = k; j <= n; j++) {
				if(i == j || i == k || j == k) continue;
				if(dis[i][j] > dis[i][k] + dis[k][j]) {
					vis[i][j] = vis[i][k] * vis[k][j];
					dis[i][j] = dis[i][k] + dis[k][j];
				} else if(dis[i][j] == dis[i][k] + dis[k][j]) {
					vis[i][j] += vis[i][k] * vis[k][j];
				}
			}
		}
	}
	ans = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = i + 1; j <= n; j++) {
			if(vis[i][j] == 2) ans++;
//			cout << vis[i][j] << ' ';
		}
//		cout << endl;
		g[i].clear();
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
		printf("%d\n", ans);
	}
	return 0;
} 
