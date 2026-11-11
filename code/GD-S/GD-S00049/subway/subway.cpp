#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e3 + 10, M = 2e4 + 10, NUM = 1e6 + 1e5;
int c, n, m, d, q, w[M], to[NUM];
vector <pair <int, int>> sub[M], g[NUM];
long long dis[N][M], Dis[NUM];
bool vis[NUM];

void Dijkstra(int s) {
	priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> q;
	q.push({0ll, s});
	for (int i = 1; i <= 2e4; i ++) dis[s][i] = 1e18;
	dis[s][s] = 0;
	while (!q.empty()) {
		int d = q.top().first, u = q.top().second; q.pop();
		if (dis[s][u] != d) continue;
		for (pair <int, int> p : g[u]) {
			int v = p.first, w = p.second;
			if (dis[s][v] <= dis[s][u] + w) continue;
			dis[s][v] = dis[s][u] + w;
			q.push({dis[s][v], v});
		}
	}
}

int bfs(int s, int t) {
	queue <int> q;
	q.push(s);
	memset(Dis, 0x3f, sizeof Dis);
	memset(vis, false, sizeof vis);
	Dis[s] = 0;
	vis[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = true;
		for (pair <int, int> p : g[u]) {
			int v = p.first;
			if (!vis[v]) {
				q.push(v);
				Dis[v] = Dis[u] + 1;
			}
		}
	}
	
	return Dis[t];
}

void planB() {
	while (q --) {
		int u, v;
		cin >> u >> v;
		cout << bfs(to[u], to[v]) * g[1][0].second + w[to[u]] + w[to[v]] << '\n';
	} 
}

void planA() {
	for (int i = 1; i <= m; i ++)
		Dijkstra(to[i]);
	while (q --) {
		int u, v;
		cin >> u >> v;
		cout << dis[to[u]][to[v]] + w[to[u]] + w[to[v]] << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i ++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i ++) {
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j ++) {
			int t, a;
			scanf("%d%d", &t, &a);
			sub[i].push_back({t, a}); 
		}
	}
	
	vector <int> v;
	for (int i = 1; i <= m; i ++) v.push_back(i);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < (int)sub[i].size(); j ++)
			v.push_back(i * (m + 1) + sub[i][j].first);
	sort(v.begin(), v.end());
	for (int i = 0; i < (int)v.size(); i ++)
		to[v[i]] = i + 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < (int)sub[i].size() - 1; j ++) {
			int t1 = i * (m + 1) + sub[i][j].first, t2 = i * (m + 1) + sub[i][j + 1].first;
			g[to[t1]].push_back({to[t2], 0});
			g[to[t2]].push_back({to[t1], 0});
		}
		for (pair <int, int> num : sub[i]) {
			int t = i * (m + 1) + num.first;
			g[to[t]].push_back({num.first, num.second});
			g[num.first].push_back({to[t], num.second});
		}
	}
	
	if (c <= 11) planA();
	else if (c <= 15) planB();
	
	return 0;
}

