#include <bits/stdc++.h>
using namespace std;
//地铁口i = 2i; 地铁站台i = 2i + 1;

#define int long long

const int N = 505;
const int M = 5005;
const int INF = 1e9;

int c, n, m, d, q;
int w[N];
int a, t;
vector<pair<int, int>> e[M];
int dis[M][M];

inline void dijkstra(int s){
	dis[s][s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while (!pq.empty()){
		pair<int, int> tp = pq.top();
		pq.pop();
		int u = tp.second;
		for (pair<int, int> lj : e[u]){
			int v = lj.first, w = lj.second;
			if (dis[s][u] + w < dis[s][v]){
				dis[s][v] = dis[s][u] + w;
				pq.push({dis[s][v], v});
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis, INF, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
		e[2 * i - 1].push_back({2 * i, w[i]});
		e[2 * i].push_back({2 * i - 1, w[i]});
	}
	int tot = m * 2;
	int k;
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a >> t;
			tot++;
			e[a * 2].push_back({tot, t});
			e[tot].push_back({a * 2, t});
			e[tot - 1].push_back({tot, 0});
			e[tot].push_back({tot - 1, 0});
		}
	}
//	for (auto u : e[12]){
//		cout << u.first << " " << u.second << "\n";
//	}
	for (int i = 1; i <= n; i++){
		dijkstra(2 * i - 1);
	}
	int s, t;
	while (q--){
		cin >> s >> t;
		cout << dis[2 * s - 1][2 * t - 1] << "\n";
	}
	return 0;
}
