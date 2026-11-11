// 2026 CSP-S B ( subway )
#include <bits/stdc++.h>
using namespace std;
namespace kqpkao_namespace{

typedef long long ll;
typedef pair<ll, int> Pli;
inline void chkMin(ll &x, ll y){ (x > y) && (x = y); }
const int N = 505, M = 5e5 + 5;
const ll inf = 1e18;
ll td[M], el[N][N];
vector<Pli> g[M];
int n, m, d, q;
inline int read();
inline ll readll();
inline void writeln(ll wx);
inline int k_main(){
	int testid = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1; i <= m; ++i){
		td[i] = readll();
	}
	for (int i = 1; i <= n; ++i){
		int c = read();
		while (c--){
			int v = read();
			ll w = readll();
			g[v].push_back(make_pair(w, i));
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			el[i][j] = (i == j ? 0ll : inf);
		}
	}
	for (int i = 1; i <= m; ++i){
		int deg = int(g[i].size());
		for (int j = 0; j < deg; ++j){
			for (int k = 0; k < deg; ++k){
				ll w = g[i][j].first + g[i][k].first;
				chkMin(el[g[i][j].second][g[i][k].second], w);
				chkMin(el[g[i][k].second][g[i][j].second], w);
			}
		}
	}
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				chkMin(el[i][j], el[i][k] + el[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; ++i){
		int x = read();
		int y = read();
		ll ans = inf;
		for (Pli xow : g[x]){
			for (Pli yow : g[y]){
				chkMin(ans, xow.first + yow.first + el[xow.second][yow.second]);
			}
		}
		writeln(ans + td[x] + td[y]);
	}
	return 0;
}
inline int read(){
	int rx = 0;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx;
}
inline ll readll(){
	ll rx = 0;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx;
}
inline void writeln(ll wx){
	static char ws[35];
	int wtp = 0;
	do {
		ws[++wtp] = wx % 10;
		wx /= 10;
	} while (wx > 0);
	while (wtp > 0){
		putchar(ws[wtp] | 48);
		--wtp;
	}
	puts("");
	return;
}

}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int k_ret = kqpkao_namespace::k_main();
	return k_ret;
}
