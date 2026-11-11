/**
 * @file CSP-S 2026
 *       Problem D. hub
 * @author BJ-S01809
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/
//password: Oct31==Dec25?

// PhigrOS 已崩溃，模拟结束。
// 感谢您的参与，愿我们在塔中重聚。

// And now we stand at the cliff itself.
// rN, from Hate - rN || Frums

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int C, T, n, k, dis[40], ans;
vector<int> G[40];
bitset<40> col, vis;
queue<int> q;

void dfs2(int u) {
	vis.set(u);
	for (auto v : G[u])
		if (col[v] && !vis[v])
			dfs2(v);
}

void dfs(int u, int l) {
	if (u == k + 1) {
		// if (col[1] && col[2] && col[3])
		// 	cerr << "OKK\n";
		vis.reset();
		int bl = 0;
		for (int i = 1; i <= n; ++i)
			if (col[i] && !vis[i])
				++bl, dfs2(i);
		if (bl > 2)
			return ;
		// cerr << "OK\n";
		memset(dis, 0x3f, sizeof dis);
		vis.reset();
		for (int i = 1; i <= n; ++i)
			if (col[i])
				q.push(i), dis[i] = 0;
		// if (col[1] && col[3]) {
		// 	for (int i = 1; i <= n; ++i)
		// 		cerr << dis[i] << " \n"[i == n];
		// }
		while (q.size()) {
			auto u = q.front();
			q.pop();
			if (vis[u])
				continue;
			vis.set(u);
			for (auto v : G[u]) {
				dis[v] = min(dis[v], dis[u] + 1);
				if (!vis[v])
					q.push(v);
			}
		}
		// if (ans != 0 && *max_element(dis + 1, dis + n + 1) == 0) {
		// 	cerr << col << ' ' << vis << '\n';
		// 	for (int i = 1; i <= n; ++i)
		// 		cerr << dis[i] << " \n"[i == n];
		// }
		ans = min(ans, *max_element(dis + 1, dis + n + 1));
		return ;
	}
	for (int i = l, f; i <= n - (k - u); ++i) {
		col.set(i);
		dfs(u + 1, i + 1);
		col.reset(i);
	}
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (cin >> C >> T; T--; ) {
		cin >> n >> k; ans = 1e9;
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 1);
		cout << ans << '\n';
		for (int i = 1; i <= n; ++i)
			G[i].clear();
	}
	return 0;
}

// I see you on last day last day last day
// 歌唱声绝无止息！
// 一去入苍天 苍天远比海更远

//15pts


// 呜呜我的 WC 没了啊……不挂分的话，100+100+56+15=271pts
// 应该是很低的分数了喵。
// 不过别停下！

// 要去到 NGOI 喵
// 要成为自己的样子喵

// 即使诞于沉寂最终消融于颓圮 今天的我仍将继续

// CSP-S 2026, liuli688 留  2026/10/31