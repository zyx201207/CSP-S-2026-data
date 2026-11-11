#include <bits/stdc++.h>
// #define int long long
// #define lson (id << 1)
// #define rson (id << 1 | 1)
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

constexpr int N = 505, M = 5e5 + 5, Q = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll INFF = 4e18;

int qu[Q], qv[Q]; ll ans[Q];
vector<pair<int, int>> G[N + M];
int hd[M];

void add(int u, int v, ll w) {
	G[u].push_back({v, w});
}

int n, m, pw[M];
ll dis[N + M]; int tag[N + M], nowtime;

void Dijkstra(int s) {
	dis[s] = 0, tag[s] = ++ nowtime;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > que;
	que.push({0, s});
	while (!que.empty()) {
		int u = que.top().second; ll nowd = que.top().first; que.pop();
		if (nowd != dis[u]) continue;
		for (auto& pir : G[u]) {
			int v = pir.first; ll w = pir.second;
			if (tag[v] != nowtime) dis[v] = INFF, tag[v] = nowtime;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				que.push({dis[v], v});
			}
		}
	}
}

void bfs(int s) {
	dis[s] = 0, tag[s] = ++ nowtime;
	queue<int> que; que.push(s);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto& pir : G[u]) {
			int v = pir.first, w = pir.second;
			if (tag[v] != nowtime) {
				dis[v] = dis[u] + w;
				tag[v] = nowtime;
				que.push(v);
			}
		}
	}
}

signed main()
{
	constexpr bool TEST = 1;
	clock_t start = clock(); 
     freopen("subway.in", "r", stdin);
     freopen("subway.out", "w", stdout);
     ios::sync_with_stdio(0), cin.tie(0);
    int cs, d, q; cin >> cs >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) cin >> pw[i];
    for (int i = 1; i <= n; i ++) {
    	int k; cin >> k;
    	for (int j = 1; j <= k; j ++) {
    		int x, t; cin >> x >> t;
    		add(i, x + n, t), add(x + n, i, t);
		}
	}
	for (int i = 1; i <= q; i ++) cin >> qu[i] >> qv[i], ans[i] = INFF;
//	Dijkstra(1);
//	cout << "t1:";
//	cerr << clock() - start << endl;
//	Dijkstra(2);
//	cout << "t2:";
//	cerr << clock() - start << endl;
//	Dijkstra(3);
//	cout << "t3:";
//	cerr << clock() - start << endl;
//	return 0;
	for (int i = 1; i <= n; i ++) {
		if (cs >= 12 && cs <= 19) bfs(i);
		else Dijkstra(i);
//		printf("i = %d\n", i);
//		for (int j = 1; j <= n + m; j ++) cout << dis[j] << ' ';
//		cout << endl;
		for (int j = 1; j <= q; j ++) {
			int u = qu[j], v = qv[j];
			while (hd[u] < (int)G[u + n].size() && G[u + n][hd[u]].first < i) hd[u] ++;
			if (hd[u] < (int)G[u + n].size() && G[u + n][hd[u]].first == i) {
				ans[j] = min(ans[j], G[u + n][hd[u]].second + dis[v + n]);
			}
			swap(u, v);
			while (hd[u] < (int)G[u + n].size() && G[u + n][hd[u]].first < i) hd[u] ++;
			if (hd[u] < (int)G[u + n].size() && G[u + n][hd[u]].first == i) {
				ans[j] = min(ans[j], G[u + n][hd[u]].second + dis[v + n]);
			}
		}
	}
	for (int i = 1; i <= q; i ++) cout << ans[i] + pw[qu[i]] + pw[qv[i]] << endl;
	if (TEST) cerr << "used: " << clock() - start << "ms\n";
    return 0;
}
