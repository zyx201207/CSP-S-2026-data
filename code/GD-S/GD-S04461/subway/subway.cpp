// 15:07 看完题目。
// 一个朴素的算法，对每一个线路都建一个虚点，连接该点和该线路上所有的站点，边权为线路走到站台时间。显然答案就是两点最段路再加上出站时间
// 由于最段路必定经过虚点，所以我们可以以所有虚点为起点，全都跑一遍dijkstra,查询的时候直接枚举虚点
// 复杂度O(nq+nmlogm) (假设sigma k = m)
// 期望获得 68 分
// 所以这个 d 的限制有什么用呢
// 15:25 想不出其他更优的算法了，开始编码吧
// 15:46 编码完成，阳历输出错误，开始调试
// 15:55 一个地方抽风了，改完过5个大阳历。不错。开下一题吧

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 510;

int e, m, n, d, q;
int C[N]; // 出站时间
vector<vector<int64_t>> Dis;
vector<pair<int, int>> E[N + M];

#define pii pair<int, int>
priority_queue<pii, vector<pii>, greater<pii>> Q;

void dijkstra (int stt, vector<int64_t> &Dis) {
	for (int i = 1; i <= n + m; i++) {
		Dis[i] = 1e17;
	}
	Dis[stt] = 0;
	while (!Q.empty()) Q.pop();
	Q.push({0, stt});

	while(!Q.empty()) {
		int now = Q.top().second;
		if (Dis[now] != Q.top().first) { Q.pop(); continue; }
		Q.pop();

		for (pii wzh : E[now]) {
			int v = wzh.first, w = wzh.second;
			if (Dis[now] + w < Dis[v]) {
				Dis[v] = Dis[now] + w;
				Q.push({Dis[v], v});
			}
		}
	}
}

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> e >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
	}

	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int v, w; cin >> v >> w;
			int u = n + i;
			E[u].push_back({v, w});
			E[v].push_back({u, w});
		}
	}


	Dis.resize(m + 3);
	for (int i = 1; i < m + 1; i++) {
		Dis[i].resize(n + m + 5);
	}

	for (int i = 1; i <= m; i++) {
		dijkstra(n + i, Dis[i]);
		// cout << i << "\n";
		// for (int j = 1; j <= n + m; j++) {
		// 	cout << Dis[i][j] << " ";
		// }
		// cout << "\n";
	}

	for (int q_id = 1; q_id <= q; q_id++) {
		int fr, to; cin >> fr >> to;
		int64_t ans = 1e17;
		for (int i = 1; i <= m; i++) {
			ans = min(ans, Dis[i][fr] + Dis[i][to]);
		}
		ans += C[fr] + C[to];
		cout << ans << "\n";
	}
}