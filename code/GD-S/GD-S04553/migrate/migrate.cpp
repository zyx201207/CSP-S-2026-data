#define ffopen(s) \
cin.tie(0)->sync_with_stdio(0); \
freopen(#s ".in", "r", stdin); \
freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const intl N = 2000000;
int C, T, n, prv[N + 10], nxt[N + 10];
intl d, xi[N + 10];
//namespace BF {
//	void slove() {
//		intl ans = 0;
//		for (int i = 1, j = 2; j <= n; j++) {
//			if (nxt[i] >= j) continue;
//			while (nxt[i] < prv[j] + 1) i++;
//			if (nxt[i] >= j) continue;
//			while (nxt[i] == prv[j] + 1) {
//				++ans;
//				i++;
//			}
//			while (nxt[i] >= prv[j] + 1) i--;
//		}
//		cout << ans << '\n';
//		
//		cerr << '\n' << T << '\n';
//		cerr << n << ' ' << d << '\n';
//		for (int i = 1; i <= n; i++) cerr << xi[i] << " \n"[i == n];
//	}
//	/*
//		hack: 5 3
//		-3 0 2 3 4
//		reason: 0 -> 4 ok, but -3 -> 0 -> 4 also ok
//	*/
//};

namespace DP1 {
	intl f[N + 10][3];
	vector<int> bic[N + 10];
	bool check(int i) {
		for (int u : bic[i]) {
			for (int v : bic[i + 1]) {
				if (u == v) return true;
			}
		} return false;
	}
	void slove() {
		for (int i = 0; i <= n + 1; i++) {
			f[i][0] = f[i][1] = f[i][2] = 0;
			bic[i].clear();
		}
		for (int i = 1, j = 2; j <= n; j++) {
			if (nxt[i] >= j) continue;
			while (nxt[i] < prv[j] + 1) i++;
			if (nxt[i] >= j) continue;
			while (nxt[i] == prv[j] + 1) {
				bic[j].emplace_back(i);
				i++;
			}
			while (nxt[i] >= prv[j] + 1) i--;
		}
		for (int i = 1; i <= n; i++) {
			if (prv[i] == i) continue;
			if (nxt[prv[i]] == i) { // ?
				f[i][2] += f[prv[i]][0] + 1;
			}
				f[i][0] += f[prv[i]][0] + 1;
				if (!check(prv[i])) {
					f[i][1] += f[prv[i]][1];
				}
			if (bic[i].size() == 1) {
				f[i][1] += f[bic[i][0]][2] + 1;
			} else if (bic[i].size() == 2) {
				intl mi = min(bic[i][0], bic[i][1]);
				f[i][1] += f[mi][2] + 2;
			}
		}
		intl ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += f[i][1];
		}
//		for (int i = 1; i <= n; i++) cerr << f[i][0] << " \n"[i == n];
//		for (int i = 1; i <= n; i++) cerr << f[i][1] << " \n"[i == n];
		cout << ans << '\n';
//		for (int i = 1; i <= n; i++) {
//			cerr << bic[i].size() << " \n"[i == n];
//		}
	}
}

void slove() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> xi[i];
	for (int i = 1, j = 1; i <= n; i++) {
		while (xi[i] - xi[j] > d) ++j;
		prv[i] = j;
	}
	for (int i = n, j = n; i >= 1; i--) {
		while (xi[j] - xi[i] > d) --j;
		nxt[i] = j;
	}
//	BF::slove();
	DP1::slove();
}
int main() {  ffopen(migrate);
	cin >> C >> T;
	while(T--) {
		slove();
		for (int i = 0; i <= n + 1; i++) {
			nxt[i] = prv[i] = xi[i] = 0;
		} 
	}
	return 0;
}

/*
mi scias ke mi neniam venos.
mi provis, sed mi ne povas fari gxin ...
gxis la ... mia OI vivo!
eble neniam gxis revidos kun vin.
*/
