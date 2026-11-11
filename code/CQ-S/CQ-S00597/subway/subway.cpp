#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct node {
	int p;
	ll w;
	bool operator>(const node &other) const {
		return w > other.w;
	}
};

const int N = 505, M = 5e5 + 5;
int C, n, m, D, q;
ll dp[N][N];
ll w[M];
vector<node> c[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> C >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while(k--) {
			int a, t;
			cin >> a >> t;
			// 站厅进轨道 (20)
			c[a].push_back({i, t});
		}
	}
	// floyd dp arr init
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	// floyd init
	for (int i = 1; i <= m; i++) {
		// 20 * 20 = 400
		for (int x = 0; x < c[i].size(); x++) {
			for (int y = 0; y < c[i].size(); y++) {
				if (x == y) continue;
				dp[c[i][x].p][c[i][y].p] = dp[c[i][y].p][c[i][x].p] = c[i][x].w + c[i][y].w;
			}
		}
	}
	// floyd 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] != -1 && dp[k][j] != -1) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		// 站外 
		// 入站厅
		ll sum = w[x] + w[y], minn = 1e18;
		// 20 * 20 = 400
		// 站厅进轨道 
		for (int i = 0; i < c[x].size(); i++) {
			for (int j = 0; j < c[y].size(); j++) {
				int stx = c[x][i].p;
				int sty = c[y][j].p;
				if (dp[stx][sty] == -1) continue;
				/*入轨道*/
				minn = min(minn, dp[stx][sty] + (c[x][i].w + c[y][j].w));
			}
		}
		cout << minn + sum << '\n'; 
	}
}
// a.n + k (m) 最多连接 20 条边
// b.n <= 500
// 在 n 图内跑 floyd
// 最猛的时候 n 点两两连边每组有 m(500000) 个
// 也就是总边有 m * n * n(50000 * 500 * 500 = 125e8)
// 但是考虑到实际上很多都是废边
// 1.也就可以边加边边 bellman-ford
//		在此之下现将边排序优化（false，边太多）

// 有环，缩点？
// 缩出一颗树 
// 圆方树，不会，舍。

// 目前看来是floyd
// a还没用上
// m 两两连边最多20条
// n 点承载的关系最多 400 条
// n 承总 400 * n(500) = 2e5
// m 承总 5e5 * 5e5 = 25e10
// n 承 < m 承s
// 有思路，先把m两两连边干出来？
// 跑 Dijkstar?
// 多此一举，边还多
// d 只是告诉边的数量？
// 应该不是，k和已经限了
// 要么 LCA，要么floyd
// LCA 需要圆方树，不行
// 故此想 floyd(n)
// 不对，bellman-ford?
//  疑似找死（125e8条边）
// 真的有125e8条边吗？
// n 俩俩连接虽然说每个最多有 500000 种可能
// 但是m也创造不了多少种可能啊，这种满可能顶多20个
// 哟西
// 跑出了每个 n 与 n 间的距离
// 每个 x, y 各有 20 种找起始线路的选择, 20 * 20 = 400
// 冷静一下，脑子有点乱了
// WA
// 过小样例 
