#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using ll = long long;
int in(void) { int x; scanf("%d", &x); return x; }
ll inl(void) { ll x; scanf("%lld", &x); return x; }
using namespace std;
const int kN = 505000;
int n; ll m, a[kN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = in(), m = inl();
	_rep(i,1,n) a[i] = inl();
	sort(a + 1, a + 1 + n);
	int L = 1, ans = 1;
	ll tot = 0;
	_rep(i,2,n) {
		tot += (i - L) * (a[i] - a[i - 1]);
		while(tot > m) tot -= a[i] - a[L], ++L;
		ans = max(ans, i - L + 1);
	}
	printf("%d\n", ans);
	return 0;
}