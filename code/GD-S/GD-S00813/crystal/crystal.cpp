#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
// #define int ll
#define OJ

constexpr int maxn = 500010;

int n;
ll m;
ll a[maxn];

signed main() {
#ifdef OJ
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#else
	freopen("crystal4.in", "r", stdin);
	freopen("crystal4.out", "w", stdout);
#endif

	cin >> n >> m;
	rep (i, 1, n) cin >> a[i];

	sort(a + 1, a + n + 1);

	int ans = 0;
	ll tot = 0;
	for (int i = 1, j = 1; i <= n; ++i) {
		tot += (a[i] - a[i - 1]) * (i - j);
		for (; j <= n && tot > m; ++j)
			tot -= (a[i] - a[j]);
		// cerr << i << ',' << j << ' ' << tot << '\n';
		// assert(j <= i);
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';

	return 0;
}
