// 2026 CSP-S C ( migrate )
#include <bits/stdc++.h>
using namespace std;
namespace kqpkao_namespace{

typedef long long ll;
const int N = 2e6 + 5, inf = 1e9;
int n, f[N], g[N], cnt[N + 50];
int qh, qt, q[N];
ll d, a[N], ans;
inline ll read();
inline void writeln(ll wx);
inline void solve(){
	n = read();
	d = read();
	for (int i = 1; i <= n; ++i){
		a[i] = read();
	}
	ans = 0;
	int nnn = n + 5;
	for (int L = 1; L <= n; ++L){
		for (int i = 0; i <= nnn; ++i){
			cnt[i] = 0;
		}
		f[L] = 0;
		g[L] = 1;
		qh = 1;
		qt = 1;
		q[1] = L;
		++cnt[0];
		for (int i = L + 1; i <= n; ++i){
			while (qh <= qt && a[i] - a[q[qh]] > d){
				cnt[f[q[qh]]] -= g[q[qh]];
				++qh;
			}
			if (qh > qt){
				f[i] = nnn;
				g[i] = 0;
			}
			else{
				f[i] = min(f[q[qh]] + 1, nnn);
				g[i] = min(cnt[f[q[qh]]], 3);
			}
//			printf("%d ~~~> %d | %d %d\n", L, i, f[i], g[i]);
			if (g[i] == 2){
				++ans;
			}
			while (qh <= qt && f[q[qt]] > f[i]){
				cnt[f[q[qt]]] -= g[q[qt]];
				--qt;
			}
			++qt;
			q[qt] = i;
			cnt[f[i]] += g[i];
		}
	}
	writeln(ans);
	return;
}
int k_main(){
	int testid = read();
	int _ = read();
	while (_ > 0){
		solve();
		--_;
	}
	return 0;
}
inline ll read(){
	ll rx = 0, rf = 1;
	char rch = getchar();
	while (rch < '0' || '9' < rch){
		if (rch == '-'){
			rf = -1;
		}
		rch = getchar();
	}
	while ('0' <= rch && rch <= '9'){
		rx = (rx << 3) + (rx << 1) + (rch ^ 48);
		rch = getchar();
	}
	return rx * rf;
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
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int k_ret = kqpkao_namespace::k_main();
	return k_ret;
}
