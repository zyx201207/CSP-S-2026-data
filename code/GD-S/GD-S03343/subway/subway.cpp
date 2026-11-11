#include <bits/stdc++.h>
#define R register
#define int long long

using namespace std;

const int N = 505, M = 5e5 + 5;
int _, n, m, d, q, w[M], f[N][N];

struct node {
	int xian, ti;
};

vector<node> v[M];

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin)), *p1 ++)

inline int rd() {
	int S = 0;
	char ch = gc();
	while(ch < '0' || ch > '9') ch = gc();
	while(ch >= '0' && ch <= '9') {
		S = (S << 3) + (S << 1) + (ch^48);
		ch = gc();
	}
	return S;
}

inline int my_min(int x, int y) {
	return x < y ? x : y;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	_  = rd(); n = rd(); m = rd(); d = rd(); q = rd();
	for(R int i = 1; i <= m; ++i)
		w[i] = rd();
	for(R int k, i = 1; i <= n; ++i) {
		k = rd();
		for(R int x, y, j = 1; j <= k; ++j) {
			x = rd(); y = rd();
			v[x].push_back({i, y});
		}
	}
	for(R int i = 1; i <= n; ++i) {
		for(R int j = 1; j <= n; ++j)
			f[i][j] = 1e18;
		f[i][i] = 0;
	}
	for(R int x, y, i = 1; i <= m; ++i) {
		for(auto I : v[i])
		for(auto J : v[i]) {
			x = I.xian; y = J.xian;
			f[x][y] = my_min(f[x][y], I.ti + J.ti);
			f[y][x] = my_min(f[y][x], I.ti + J.ti);
		}
	}
	
	for(R int k = 1; k <= n; ++k)
	for(R int i = 1; i <= n; ++i)
	for(R int j = 1; j <= n; ++j)
		f[i][j] = my_min(f[i][j], f[i][k] + f[k][j]);
	
	while(q --) {
		int st = rd(), en = rd(), ans = 1e18;
		if(st == en) {
			cout << "0" << endl;
			continue;
		}
		for(auto I : v[st])
		for(auto J : v[en])
			ans = my_min(ans, f[I.xian][J.xian] + I.ti + J.ti);
		cout << ans + w[st] + w[en] << endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

为什么 csp 会出卡常题啊！（不加快读：1100 ms，加了：750 ms） 
100 pts
*/
