#include <bits/stdc++.h>
#define int long long
#define N 200005
#define rep(x, y, z) for (int x = y; x <= z; x++)
#define rrep(x, y, z) for (int x = y; x >= z; x--)
#define inf 1e18
using namespace std;
int n, m, a[N], t, ans;
#undef int
int main() {
#define int long long
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];
	rrep (i, 31, 0) {
		int k = (1ll << i);
		t = 0;
		rep (i, 1, n) if (a[i] & k) t++;
		if (t < m) continue;
		t = 0;
		rep (i, 1, n) if (a[i] & k) a[++t] = a[i];
		n = t;
		ans += k;
	}
	cout << ans;
	return 0;
}
