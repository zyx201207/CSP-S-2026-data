#include <bits/stdc++.h>
using namespace std;

const int N = 114514 * 5;
int n, m, s, dis[N], vis[N];

vector<pair<int, int>> e[N];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> n >> m >> s;
	
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z});
	}
	
	for (int i = 1; i <= n; i++)
		if (i != s)
			dis[i] = 1e9;
	
	q.push({0, s});
	
	while (!q.empty()) {
		auto i = q.top;
		q.pop();
		
		int d = i.first;
		int id = i.second;
		
		if (vis[id])
			continue;
		vis[id] = 1;
		
		for (auto j : e[id]) {
			int x = j.first;
			int w = j.second;
			
			if (dis[x] > dis[id] + w) {
				dis[x] = dis[id] + w;
				q.push({dis[x], x});
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	
	return  0;
}

