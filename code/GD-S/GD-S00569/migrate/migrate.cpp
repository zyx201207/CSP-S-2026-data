#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int maxn = 2e6;
int n;
LL d, x[maxn + 10];
int l[maxn + 10], r[maxn + 10];
int fl[5010][5010], ft[5010][5010];
void solve1() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		int pos = 0;
		for (int i = 1; i <= n; ++i) {
			if (x[n] - x[i] <= d && x[i] - x[1] <= d) {
				pos = i;
				break;
			}
		}
		for (int i = 1, ptr = 1; i <= n; ++i) {
			while (ptr <= n && x[ptr] - x[i] <= d) ++ptr;
			--ptr;
			r[i] = ptr;
		}
		for (int i = n, ptr = n; i >= 1; --i) {
			while (ptr >= 1 && x[i] - x[ptr] <= d) --ptr;
			++ptr;
			l[i] = ptr;
		}
		LL ans = 0;
		for(int i = 1; i < pos; ++i) {
			int p = lower_bound(l + 1, l + 1 + n, r[i] - 1) - l;
			if (p == n + 1) continue;
			int pp = upper_bound(l + 1, l + 1 + n, r[i] - 1) - l;
			int ppp = upper_bound(x + 1, x + 1 + n, x[i]) - x;
			if (ppp == n + 1) continue;
			if (pp < max(p, ppp)) continue;
			ans += pp - max(p, ppp);
		}
		cout << ans << "\n";
	}
}
int q[5010], qi[5010], hd, tl;
LL ts[5010];
void solve2() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			fl[i][i] = 0, ft[i][i] = 1;
		}
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			hd = tl = 0;
			for (int j = 0; j <= n; ++j) ts[j] = 0;
			for (int j = i + 1; j <= n; ++j) {
				while (tl > hd && x[j] - x[qi[hd]] > d) ts[q[hd]] -= ft[i][qi[hd]], ++hd; 
				if (x[j] - x[i] <= d) {
					fl[i][j] = 1, ft[i][j] = 1;
					while (tl > hd && fl[i][j] < q[tl-1]) ts[q[tl-1]] -= ft[i][qi[tl-1]], --tl;
					q[tl++] = fl[i][j];
					qi[tl-1] = j;
					ts[fl[i][j]] += ft[i][j];
				} else {
					if (hd >= tl) fl[i][j] = 0, ft[i][j] = 0;
					else {
						fl[i][j] = q[hd] + 1;
						ft[i][j] = ts[q[hd]];
						if (ft[i][j] == 2) ++ans;
						while (tl > hd && fl[i][j] < q[tl-1]) ts[q[tl-1]] -= ft[i][qi[tl-1]], --tl;
						q[tl++] = fl[i][j];
						qi[tl-1] = j;
						ts[fl[i][j]] += ft[i][j];
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c; cin >> c;
	if (c == 13 || c == 14) solve1();
	else if (c <= 10) solve2();
	return 0;
}

