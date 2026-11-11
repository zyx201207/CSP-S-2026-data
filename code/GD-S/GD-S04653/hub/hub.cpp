#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 20;
int c, t, n, k, f[N], vis[N], dis[N];
vector<int> g[N];

void dfs(int x, int pre) {
	vis[x] = 1;
	for (auto v : g[x]) {
		if (v == pre || f[v] != 1) continue;
		dfs(v, x);
	}
}
void dfs2(int x, int pre) {
	dis[x] = dis[pre] + 1;
	for (auto v : g[x]) {
		if (v == pre) continue;
		dfs2(v, x);
	}
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k; int ans = LLONG_MAX;
		r(n) g[i].clear();
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int s = 1; s < (1 << n); s++) {
			// 枚举每种情况，然后位运算算出每个点是c否被选中。
			int cnt = 0, mx = 0;
			rep(i, 0, n - 1) f[i + 1] = (s >> i) & 1;
			r(n) cnt += f[i]; if (cnt != k) continue;
			memset(vis, 0, sizeof vis), cnt = 0;
			r(n) if (f[i] && !vis[i]) cnt++, dfs(i, 0);
			if (cnt > 2) continue;
			r(n) if (!f[i]) {
				dis[0] = -1, dfs2(i, 0); int mn = LLONG_MAX;
				rep(j, 1, n) if (f[j]) mn = min(mn, dis[j]);
				mx = max(mx, mn); 
			}
			ans = min(ans, mx);
		}
		cout << ans << "\n";
	}
	return 0;
}
// 17:10 开题，先玩一把小恐龙
// 17:13 达成成就，开写，考虑 2^n 枚举每个情况，然后判断是否两个连通块是简单的
// 并且计算通勤半径也是简单的。复杂度最多是 O(2^n\times n^2)，15' get. 还算比较大方的。 
// 17:19 吓死我了，还以为卡退了，刚刚突然给我切到 pdf 去了。 
// 这个题这么多个 min/max 套起来很像是二分啊，不过二分之后怎么做呢？等会再想吧。 
// 17:27 打完了 15'，不过还要调一下，时间应该够，调完这题先检查一次。 
// 现在大家应该都是 200pts了，我的优势可能只剩切 T2 早了，但是后面两题并没有想到什么非平凡部分分。
// 假定大众分比自己高一点，现在情况是 100+100+24+15=239，那么假设现在大众分是 260。
// 先检查，检查完再继续冲部分分。 
