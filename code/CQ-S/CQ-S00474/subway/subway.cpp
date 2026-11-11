#include <bits/stdc++.h>
using namespace std;
const int S = 1 << 20;
char buf[S], *p1, *p2;
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
inline void rd(int &x) {
	x = 0; char c = 0;
	while (c < '0' || c > '9') c = gc;
	while (c >= '0' && c <= '9') x = x * 10 - '0' + c, c = gc;
}
namespace WorldMachine {
	typedef long long ll;
	const int N = 505, M = 5e5 + 5;
	int c, n, m, d, q, w[M];
	ll dis[N][N], tmp[M];
	vector<pair<int, int> > vp[N], ve[M];
	void main() {
		rd(c), rd(n), rd(m), rd(d), rd(q);
		for (int i = 1; i <= m; i++) rd(w[i]);
		for (int i = 1; i <= n; i++) {
			int k; rd(k);
			vp[i].resize(k);
			for (int j = 0; j < k; j++) {
				rd(vp[i][j].first), rd(vp[i][j].second);
				ve[vp[i][j].first].push_back({i, vp[i][j].second});
			}
		}
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		memset(tmp, 0x3f, sizeof(tmp));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vp[i].size(); j++)
				tmp[vp[i][j].first] = vp[i][j].second;
			for (int j = i + 1; j <= n; j++) {
				for (int k = 0; k < vp[j].size(); k++)
					dis[i][j] = min(dis[i][j], tmp[vp[j][k].first] + vp[j][k].second);
				dis[j][i] = dis[i][j];
			}
			for (int j = 0; j < vp[i].size(); j++)
				tmp[vp[i][j].first] = 0x3f3f3f3f3f3f3f3fll;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				cerr << dis[i][j] << " \n"[j == n];
//		for (int i = 1; i <= m; i++) {
//			for (auto [x, y] : ve[i]) cerr << i << " : " << x << ' ' << y << '\n';
//			cerr << '\n';
//		}
		while (q--) {
			int x, y; rd(x), rd(y);
			ll ans = 0x3f3f3f3f3f3f3f3fll;
			for (int i = 0; i < ve[x].size(); i++)
				for (int j = 0; j < ve[y].size(); j++)
					ans = min(ans, ve[x][i].second + dis[ve[x][i].first][ve[y][j].first] + ve[y][j].second);
			cout << ans + w[x] + w[y] << '\n';
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0);
	return WorldMachine::main(), 0;
}
/*
从线路的角度考虑，如果先预处理出任意两条 线路 之间互达的最小时间
那么做一次询问就可以 O(d^2)，d 很小所以可以接受
考虑如何预处理，肯定要建图跑 Floyd，线路作为点，而边权是什么？
对于两个线路，枚举它们的公共点，取 min{t + t} 作为边权即可？
这步枚举可以采用一些手段优化常数。
时间复杂度 O(nΣk + n^3 + qd^2)，第一部分常数较小，应该是可以接受的
*/
