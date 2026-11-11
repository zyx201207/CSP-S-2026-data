/*
欢迎关注洛谷 kaikai_qwq(uid = 1106246) qwq

- 空间炸了 / 小了吗？
- 边界特判了吗？
-  多测清空了吗？
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
vector <int> G[MAXN];
int dp[MAXN], in[MAXN]; 
bool vis[MAXN];
int ans[MAXN];
int last[MAXN];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], dp[i] = 1;
	for (int i = n; i >= 1; i--) {
		if (!last[a[i]]) {
			G[i].push_back(i + 1);
			in[i + 1]++;
			vis[i] = 1;
		} else {
			G[i].push_back(last[a[i]]);
			in[last[a[i]]]++;
		}
		last[a[i]] = i;
	}
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (!in[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : G[u]) {
			dp[v] += dp[u];
			if (!(--in[v])) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		if (vis[i]) ans[a[i]] += dp[i];
	for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i < m) cout << ' '; 
	}
	cout << '\n';
	return 0;
}
/*
考虑在 [i + 1, n] 开头加入 i 的影响：

- 若有与 a[i] 相等的，就继承上一个相等位置的，因为这中间都会被删掉
- 否则，相等于 [i + 1, n] 的答案加上了一个 a[i]

怎么感觉好像消消乐（？ 

这个貌似可以建图，显然是一个 DAG

然后能到达所有初始点的数量就是答案，这个直接拓扑一遍 

做完了？？？ 

小样例都是对的！ 

大样例过了，我 AK 了？！

赛前完全没有想过 AK 的这么轻松（ 

但是我 T4 是不是用了超纲知识（，毕竟拓扑是 S 的 
*/
