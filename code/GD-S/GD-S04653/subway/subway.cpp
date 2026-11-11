#include <bits/stdc++.h>
#define int long long
#define r(x) for (int i = 1; i <= x; i++)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

const int N = 5e5 + 50, M = 505;
int c, n, m, d, q, w[N], dis[M][M];
vector<pair<int, int>> v[N];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	r(m) cin >> w[i];
	r(n) {
		int k, a, t; cin >> k;
		// i号地铁，然后有k个站，站是a，到站换乘到站厅需要t
		// 考虑对于每个地铁站存有哪几个地铁经过，以及分别到对应的要走多远
		// 随后用 O(d^2) 连边 
		rep(j, 1, k) {
			cin >> a >> t;
			v[a].push_back({i, t});
			// a 这个站要到 i 号地铁，需要t的时间 
		}
	}
	memset(dis, 0x3f, sizeof dis);
	r(n) dis[i][i] = 0;
	r(m) {
		int sz = v[i].size();
		rep(f, 0, sz - 1) rep(g, 0, sz - 1) {
			if (f == g) continue;
			int v1 = v[i][f].first, v2 = v[i][g].first;
			int w1 = v[i][f].second, w2 = v[i][g].second;
			dis[v1][v2] = min(dis[v1][v2], w1 + w2);
		}
	}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) 
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y; int ans = LLONG_MAX / 2;
		for (auto t1 : v[x]) for (auto t2 : v[y]) {
			int v1 = t1.first, w1 = t1.second;
			int v2 = t2.first, w2 = t2.second;
			ans = min(ans, dis[v1][v2] + w1 + w2);
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
// 15:13 疑似会了？Yes!!! 优势在我。 
// 15:20 7min 写完 1.6k，我真厉害。开始调。 
// 15:23 发现是 dis[i][i] 赋成 1 了，我好唐。 
// 15:25 过了 1,2，第三个过不去，输出 inf，不知道为什么。 
// 15:27 发现是 n,m 打反了，但是在 #5 又卡了
// 15:33 ok，vector 开小了，通过所有大样例！会赢的吗？
// 检测大样例是否能卡满，可以的。O2 0.3s，应该不会被卡了，不拍了。 
// 17:44 不对！！！大样例的 d=2，并不能卡满，自己需要造数据！ 
// 17:52 好像自己也卡不满，就这样吧，qd^2 发发力肯定能过，才 4e7. 
