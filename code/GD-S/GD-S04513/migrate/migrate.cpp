#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;


bool vis[N];
long long dis[N], dis1[N], dis2[N];
int a[N];
void dj(int s, vector<int> id[]) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	queue<int> q;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto v : id[u]) {
			if (dis[v] >= dis[u] + 1) {
				dis2[v] = dis1[v];
				dis1[v] = dis[v];
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> id[n + 10];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (abs(a[i] - a[j]) <= d) {
					id[i].push_back(j);
					id[j].push_back(i);
				}
			}
		}
		long long cnt = 0; 
		for (int i = 1; i <= n; i++) {
			dj(i, id);
			for (int j = 1; j <= n; j++) {
				if (dis[j] == dis1[j] && dis[j] != dis2[j]) {
					cnt++;
				}
			}
		}
		cout << cnt / 2 << '\n';
	}
	
	return 0;
}
