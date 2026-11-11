#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k;
vector<int> vt[2005];
int col[2005], f[2005];
void bfs(int u) {
	memset(f, 0, sizeof(f));
	queue<int> q;
	f[u] = 1;
	q.push(u);
	while(!q.empty()) {
		int h = q.front();
		q.pop();
		for (int v : vt[h]) {
			if (col[v] && !f[v]) {
				f[v] = 1;
				q.push(v);
			}
		}
	}
}
int dis[2005];
void bfs2(int u) {
	queue<pair<int, int>> q;
	memset(f, 0, sizeof(f));
	f[u] = 1;
	dis[u] = 0;
	q.push({u, 1});
	while(!q.empty()) {
		int h = q.front().first;
		int way = q.front().second;
		q.pop();
		for (int v : vt[h]) {
			if (f[v]) continue;
			f[v] = 1;
			dis[v] = min(way, dis[v]); 
			q.push({v, way + 1});
		}
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) vt[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		int ans = 1e18;
		for (int i = 0; i < (1 << n); i++) {
			int m = i;
			int id = 1, ck = 0;
			bool ok = 1;
			memset(col, 0, sizeof(col));
			memset(f, 0, sizeof(f));
			for (int i = 0; i < n; i++) {
				if (m & (1 << i)) {
					col[i + 1] = 1;
					ck++;
				}
			}
//			cout << ck << '\n';
			if (ck != k) continue;
			int cn = 0;
			for (int i = 1; i <= n; i++) {
				if (col[i] && !f[i]) {
					if (cn < 2) {
						cn++;
						bfs(i);
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			if (!ok) continue;
			memset(dis, 0x3f, sizeof(dis));
			for (int i = 1; i <= n; i++) {
				if (col[i]) {
					bfs2(i);
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				cnt = max(cnt, dis[i]);
			}
//			cout << cnt << '\n';
			ans = min(ans, cnt);
        }
	    cout << ans << '\n';
	}
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
