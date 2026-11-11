#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair <ll, int>;

const int N = 510;
const int M = 5e3 + 10;
const int Can = 1e3 + 10;

int C, n, m, d, q; // 测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[M], tot;

bool vis[M * 5];
ll dis[Can][Can], pak[M * 5];

struct edge { int to; ll w; };
vector <edge> linker[M * 5];

void Dijkstra(int st) {
	priority_queue <pli> que;
	que.push(make_pair(0ll, st));
	
	memset(pak, 0x3f, sizeof(pak));
	memset(vis, 0, sizeof(vis));
	pak[st] = 0;
	
	while (!que.empty()) {
		int h = que.top().second; que.pop();
		
		if (vis[h]) continue;
		vis[h] = 1;
		
		for (auto i : linker[h]) {
			int to = i.to, w = i.w;
			
			if (pak[to] > pak[h] + w) {
				pak[to] = pak[h] + w;
				if (!vis[to]) que.push(make_pair(-pak[to], to));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> C >> n >> m >> d >> q;
	
	tot = m;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	
	for (int i = 1; i <= n; i++) {
		int len; cin >> len;
		
		if ((C >= 9 && C <= 11) || len == 2) {
			int a, t; cin >> a >> t;
			int b, p; cin >> b >> p;
			
			linker[a].push_back({ b, t + p });
			linker[b].push_back({ a, t + p });
			continue;
		}
		
		for (int pro = 1, a, t, b, q; pro <= len; pro++) {
			cin >> b >> q;
			
			linker[b].push_back({ ++tot, q });
			linker[tot].push_back({ b, q });
			if (pro == 1) continue;
			
			linker[tot - 1].push_back({ tot, 0 });
			linker[tot].push_back({ tot - 1, 0 });
			a = b, t = q;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		Dijkstra(i);
		
		for (int j = 1; j <= m; j++)
			if (i != j) dis[i][j] = w[i] + pak[j] + w[j];
	}
	
	for (int pro = 1; pro <= q; pro++) {
		int x, y; cin >> x >> y;
		cout << dis[x][y] << "\n";
	}
	
	return 0;
}

/*
服了，今年 T2 咋又是图论

首先 1 ~ 8 没啥问题，纯暴力，qm * log n 

特殊性质 A：每条路线最多经过两个地铁站 

这意味着每条线路代表的关系可以由原来的五条边 -> 一条边，边数大大减少，可以直接跑最短路了

目前可以拿下 1 ~ 11 了 

*/
