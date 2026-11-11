#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL c, T, a[2000006], vis[2000006];
LL dis[2000006], num[2000006];

vector< int > E[2000006];

void dijkstra(int &n, int s) {
	
	for (int i = 1; i <= n; i ++) {
		dis[i] = 0x3f3f3f3f3f3f3f3f;
		vis[i] = 0;
		num[i] = 0;
	}
	
	priority_queue< pair<LL, int> > q;
	q.push({0, s});
	dis[s] = 0; num[s] = 1;
	
	while (!q.empty()) {
		
		int u = q.top().second;
		q.pop();
		
		if (vis[u])
			continue;
		vis[u] = 1;
		
		for (int v : E[u]) {
			if (dis[v] < dis[u] + 1) 
				continue;
			else if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				num[v] = 1;
				q.push({-dis[v], v});
			} else {
				num[v] ++;
			}
		}
	}
}

void solve() {
	
	int n, d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (abs(a[i] - a[j]) <= d)
				{ E[i].push_back(j), E[j].push_back(i); }
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		dijkstra(n, i);
		for (int j = 1; j <= n; j ++) {
			if (num[j] / 2 == 2) {
				ans ++;
			}
		}
	}
	
	ans = ans / 2;
	
	cout << ans << endl;
	
	for (int i = 1; i <= n; i ++) {
		E[i].clear();
		a[i] = 0;
	}
}

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	
	while (T --) {
		
		solve();
	} 
	
	return 0;
} 
