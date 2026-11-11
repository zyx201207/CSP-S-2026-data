#include <bits/stdc++.h>
using namespace std;
int w[500010];
int t[1000010], nxt[1000010], cnt, to[1000010], head[1000010];
void add(int u, int v, int tt) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt]  = v;
	t[cnt] = tt;
}
mt19937 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
 
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i]; // 进站时间
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= 2 * k[i]; ++j) {
			int ttt;
			cin >> ttt;
			add(i, j, ttt);
			add(j, i, ttt);
		}
	}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y; 
		// 总步行时间为进出站和换乘的步行时间之和
		// 最短路？ 
	}
	cout << random(0, 1000100) << "\n";
	return 0;
}
