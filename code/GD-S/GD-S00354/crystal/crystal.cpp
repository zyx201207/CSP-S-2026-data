#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (b); i >= (int)(a); --i)
using LL = long long;
using Pii = pair<int, int>;
#define fst first
#define snd second

namespace gdb7
{
	LL a[500010], suf[500010];
	signed main(void) {
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		int n;
		LL m;
		scanf("%d%lld", &n, &m);
		rep (i, 1, n) {
			scanf("%lld", a + i);
		}
		sort(a + 1, a + 1 + n);
		LL l = 1, curw = 0, ans = 0;
		rep (r, 1, n) {
			curw += (a[r] - a[r - 1]) * (r - l);
			while (curw > m) {
				curw -= a[r] - a[l];
				++l;
			}
//			assert(l <= r && curw >= 0);
//			cerr << l << " " << r << " " << curw << endl;
			ans = max(ans, r - l + 1);
		}
		printf("%lld", ans);
		return 0;
	}
};

signed main()
{
	return gdb7::main();
}
