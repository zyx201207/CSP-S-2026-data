//From: CSP-S
//Problem: T2地铁（subway）
//文件名: subway.in/.out/.cpp
//时间限制: 1000 ms
//空间限制: 1024 MiB 
//预期得分: 32 pts
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int M = 5e5 + 10;
constexpr int M1 = 500 + 10;

int c, n, m, d, qq;//地铁数、站数 
int w[M];
int k[M];
int a[M1][M1], t[M1][M1], f[M1][M1];
bool vis[M1];
vector <int> s[M1];//第 i 个节点的地铁有这些 
struct Node {
	int u;//在第 u 个节点
	ll spend;//花费为 spend
	int sub;//在第 sub 条地铁上
	int id; 
	bool operator < (const Node &others) const {
		return spend > others.spend;
	}
};
priority_queue <Node> q;

ll bfs(int st, int ed) {
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof vis);
	for (int sub : s[st]) q.push({st, 0, sub, f[sub][st]});
	vis[st] = true;
	while (!q.empty()) {
		Node p = q.top();
		q.pop();
		int u = p.u;
		ll spend = p.spend;
		int sub = p.sub, id = p.id;
//		cout << u << ", " << spend << ", " << id << "\n";
//		for (int new_sub : s[u]) {
//			if (new_sub == sub) continue;
		for (int i = 1; i <= k[sub]; i ++) {//枚举第 new_sub 条地铁上的全部站点 
//			cout << spend << " + " << "t[" << sub << "][" << id << "] = " << t[sub][id] << " + " << "t[" << sub << "][" << i << "] = " << t[sub][i] << " + " << w[st] << " + " << w[ed] << "\n";
			if (a[sub][i] == ed) return spend + t[sub][id] + t[sub][i] + w[st] + w[ed]; //到终点了 
			for (int new_sub : s[a[sub][i]]) {
				if (sub == new_sub) continue;
				int v = a[sub][i];
				if (vis[v]) continue;
				vis[v] = true;
//				cout << "to " << v << ", " << new_sub << "\n";
				q.push({v, spend + t[sub][i] + t[sub][id], new_sub, f[new_sub][v]});
//				cout << i << ", t[" << sub << "][" << id << "]=" << t[sub][id] << ", t[" << sub << "][" << i << "]=" << t[sub][i] << "ww\n";
//				if (ed == v) return spend + t[sub][i] + t[sub][id] + w[st] + w[ed];
			}
		}
//		}
	}
	return 0;
}

void solve1() {
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
			s[a[i][j]].push_back(i);
			f[i][a[i][j]] = j;
		}
	}
//	for (int i = 1; i <= m; i ++) {
//		for (int sub : s[i]) cout << sub << " ";
//		cout << "\n";
//	}
	while (qq --) {
		int x, y;
		cin >> x >> y;
		cout << bfs(x, y) << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> qq;
	solve1(); 
	return 0;
}
