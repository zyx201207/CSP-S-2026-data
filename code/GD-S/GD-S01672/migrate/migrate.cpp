#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5005, inf = 1e18; 
int n, d, x[maxn], dis[maxn][maxn], vis[maxn];
vector <int> G[maxn];
void bfs(int st) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	queue <pair <int, int>> que; que.push({st, 0}), dis[st][st] = 0;
	while (que.size()) {
		int u = que.front().first, s = que.front().second; que.pop();
		if (vis[u]) continue; vis[u] = true;
		for (int i = u - 1; i >= 1; i--) 
			if (x[u] - x[i] <= d && dis[st][i] > s + 1) dis[st][i] = s + 1, que.push({i, s + 1});
			else break;
		for (int i = u + 1; i <= n; i++)
			if (x[i] - x[u] <= d && dis[st][i] > s + 1) dis[st][i] = s + 1, que.push({i, s + 1});
			else break;
	}
	return;
}
void solve(int ans = 0) {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = inf;
	for (int i = 1; i <= n; i++) bfs(i);
	for (int u = 1; u <= n; u++) 
		for (int v = u + 2; v <= n; v++) {
			int cnt = 0;
			for (int k = u + 1; k < v; k++) {
				if (dis[u][k] + dis[k][v] == dis[u][v]) cnt++;
				if (cnt > 2) break;
			} 
			if (cnt == 2) ans++;
		}
	return cout << ans << '\n', void();
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	int C, T; cin >> C >> T;
	while (T--) solve();
	return 0;
}
/*
先口胡一下
假设目前有一对极小对 (u,a,b,v) 满足 u->a->v 且 u->b->v
则答案则为 pre[u] * suf[v] 其中味前驱/后缀中到达某点且路线唯一的点数
考虑如何求出极小点对 (u,v) 事实上 (u,a,b,v) 只可能是4个相邻的岛屿，直接判断即可 
主要是要知道 pre 怎么求，而 suf 同理
目前来说，可以固定一个 u 然后 O(nlogn) 的求解 suf[u]  可以拿到 40pts
完了口胡全错，只能写一个 n^3 的了 
人活着就是为了黑部奈叶香
fc migrate.out migrate1.ans
最后五分钟 n^3 不知道哪里错了 
也就是说，是 migrate 赢了，最强的战绩，铭刻于广大附中 
*/
