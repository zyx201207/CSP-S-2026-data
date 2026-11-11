#include <bits/stdc++.h>

using namespace std;

using ll = long long; using ull = unsigned long long;
#define REP(i, l, r) for(int i = (l); i <= (r); ++i)
#define PER(i, r, l) for(int i = (r); i >= (l); --i)

bool mST;

namespace Main {

	const int IOSIZE = (1 << 20);
	char ibuf[IOSIZE], *p1 = ibuf, *p2 = ibuf;
	#define gc() (((p1 == p2) && (p1 = (p2 = ibuf) + fread(ibuf, 1, IOSIZE, stdin))), (p1 == p2) ? EOF : *p2++)
	template<typename T>void read(T &x) {
		x = 0;bool f = 0;char c = gc();
		while(!(47 < c && c < 58)) f |= (c == '-'), c = gc();
		while(47 < c && c < 58) x=  (x << 1) + (x << 3) + (c ^ 48), c=gc();
		if(f) x = -x;
	}
	const int N = 500 + 5;
	const int M = 5e5 + 5;
	int cid;
	int n, m, D, Q;
	ll w[M];
	ll d[N][N];
	pair<int, int> G[M][20];
	int L[M];
	int main() {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		read(cid), read(n), read(m), read(D), read(Q);
		// cin >> cid >> n >> m >> D >> Q;
		REP(i, 1, m) read(w[i]);
		REP(i, 1, n) {
			int len;
			int x, v;
			read(len);
			REP(j, 0, len - 1) {
				read(x), read(v);
				// cin >> x >> v;
				G[x][L[x]++] = {i, v};
				// G[x].push_back({i, v});
			}
		}
		// return 0;
		memset(d, 0x3f, sizeof(d)); REP(i, 1, n) d[i][i] = 0;
		REP(i, 1, m){
			for(int p = 0; p < L[i]; ++p){
				for(int q = p + 1; q < L[i]; ++q) {
					int x = G[i][p].first, y = G[i][q].first;
					d[x][y] = d[y][x] = min(d[x][y], (ll)G[i][p].second + G[i][q].second);
				}
			}
		}

		REP(k, 1, n) REP(i, 1, n) REP(j, 1, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		// cout << d[1][2] << '\n';
		while(Q--) {
			int x, y;
			read(x), read(y);
			// cin >> x >> y;
			ll ans = 9e18;
			for(int i = 0; i < L[x]; ++i) for(int j = 0; j < L[y]; ++j)
				ans = min(ans, d[G[x][i].first][G[y][j].first]+G[x][i].second+G[y][j].second);
			cout << ans + w[x] + w[y] << '\n';
		}
		return 0; 
	}
}

bool mED;

int main() {
#ifndef Ace
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway.err", "w", stderr);
#endif
	Main::main();
	
	cerr << fixed << setprecision(3) << "Time:" << 1. * clock() / CLOCKS_PER_SEC << "s" << '\n';
	cerr << "static Memory: " << abs(&mST - &mED) / 1048576. << "mb" << '\n'; 
	return 0;
} 
/*
1s 1024M

哦哦哦，地铁不需要时间，哈哈哈哈

为什么会要卡常?
*/