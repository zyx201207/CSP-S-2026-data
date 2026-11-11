#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MAXN = 2e6 + 5;

template<typename T> void chkMin(T &x, T y) { x = y < x ? y : x; }
template<typename T> void chkMax(T &x, T y) { x = y > x ? y : x; }

int tid, tc, n, prv[MAXN], nxt[MAXN];
int f[MAXN], g[MAXN], cl[MAXN], cr[MAXN], buc[MAXN];
ll d, x[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> tid >> tc;
	while (tc--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		
		for (int r = 2, l = 1; r <= n; ++r) {
			while (l <= r && x[r] - x[l] > d) ++l;
			prv[r] = l;
		}
		for (int l = n - 1, r = n; l; --l) {
			while (r >= l && x[r] - x[l] > d) --r;
			nxt[l] = r;
		}
		
		fill(buc, buc + n + 1, 0);
		++buc[nxt[1]];
		f[1] = 1;
		for (int i = 2, p = 1; i <= n; ++i) {
			while (p <= min(prv[i], i - 1)) --buc[nxt[p++]];
			f[i] = 1 + buc[i];
			cl[i] = buc[i + 1];
			if (i >= p) ++buc[nxt[i]];
			if (nxt[prv[i]] == i) f[i] += f[prv[i]];
		}
		
		fill(buc, buc + n + 1, 0);
		++buc[prv[n]];
		g[n] = 1;
		for (int i = n - 1, p = n; i; --i) {
			while (p >= max(nxt[i], i + 1)) --buc[prv[p--]];
			g[i] = 1 + buc[i];
			cr[i] = buc[i - 1];
			++buc[prv[i]];
			if (prv[nxt[i]] == i) g[i] += g[nxt[i]];
		}
		
		ll ans = 0;
		for (int i = 2; i < n - 1; ++i) {
			int x = cl[i] + (prv[i] < i && nxt[prv[i]] == i + 1 ? f[prv[i]] : 0);
			int y = cr[i + 1] + (nxt[i + 1] > i + 1 && prv[nxt[i + 1]] == i ? g[nxt[i + 1]] : 0);
			ans += (ll)x * y;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
