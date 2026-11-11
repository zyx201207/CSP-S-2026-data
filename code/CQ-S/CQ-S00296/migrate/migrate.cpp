#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define ft first
#define sd second
#define eb emplace_back
#define pb push_back
template<class T> inline void gmax(T& x, T y) {if (x < y) x = y;}
template<class T> inline void gmin(T& x, T y) {if (x > y) x = y;}
const int N = 2e6 + 10, M = 5e6 + 10, inf = 0x3f3f3f3f, mod = 998244353;
const ll linf = 0x3f3f3f3f3f3f3f3f;
inline void filo(string in, string out, int op = 3) {if (op & 1) freopen((in + ".in").c_str(), "r", stdin); if (op & 2) freopen((out + ".out").c_str(), "w", stdout);}
int c, t, n, fa[N], cnt[N], dfn[N], siz[N], dep[N], sum[N], son[N], mnson[N], mnd[N], mxd[N], mxson[N];
ll d, x[N], ans;
inline void clear(int i) {cnt[i] = siz[i] = son[i] = sum[i] = mnson[i] = dep[i] = dfn[i] = mxson[i] = 0;}

void solve2(int rt, int ed) {
	for (int i = ed; i <= rt; i++) cnt[i] = fa[i - 1] == fa[i] ? cnt[i - 1] + 1 : 0, siz[i] += 1, fa[i] && (siz[fa[i]] += siz[i]), son[fa[i]]++, mxson[fa[i]] = i;
	for (int i = rt; i >= ed; i--) mnson[fa[i]] = i;
	dfn[rt] = dep[rt] = 1;
	clear(rt + 1);
	for (int i = ed; i <= rt; i++) sum[i] = sum[mnson[i]] + son[i];
	for (int i = rt - 1; i >= ed; i--) 
		dep[i] = dep[fa[i]] + 1, dfn[i] = fa[i + 1] == fa[i] ? dfn[i + 1] + siz[i + 1] : dfn[fa[i]] + 1;
	for (int i = rt, fl = 0; i >= ed; i--) {
		if (dep[i] != dep[i + 1]) fl = 0, mxd[dep[i]] = i;
		if (son[i] && !fl) {
			fl = 1;
			if (dep[i - 1] == dep[i] && dep[i - 2] != dep[i]) {
				if (dep[i + 1] == dep[i]) ans += 1ll * (mxd[dep[i]] - i) * sum[i];
				if (son[i] == 1) ans += sum[i - 1];
			}
		}
		mnd[dep[i]] = i;
	}
	for (int i = 1; i < dep[ed]; i++) {
		for (int j = mxd[i], k = mxd[i + 1]; j >= mnd[i]; j--) {
			while (k > mnd[i + 1] && k - 1 >= mxson[j]) --k;
			if (k >= mxson[j] && dep[k + 1] == dep[k]) ans += sum[k + 1];
		}
	}
	for (int i = dep[ed], tmp = 0; i > 1; i--)
		if (mnd[i] != mxd[i]) ans += tmp = sum[mnd[i] + 1];
		else ans += tmp;
}

void solve() {
	cin >> n >> d, ans = 0;
	for (int i = 1; i <= n; i++) cin >> x[i], clear(i);
	int lt = n;
	for (int i = n - 1, j = n; i; i--) {
		while (x[j] - x[i] > d) j--;
		if (j == i) fa[i] = 0, solve2(lt, i + 1), lt = i;
		else fa[i] = j;
	}
	solve2(lt, 1);
	cout << ans << '\n';
}

int main() {
	filo("migrate", "migrate");
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> c >> t;
	while (t--) solve();


	return 0;
}

