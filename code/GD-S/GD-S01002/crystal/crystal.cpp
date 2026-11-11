#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using cint = const int;
using cLL = const long long;
using uint = unsigned int;
using uLL = unsigned long long;

#define N 500005
#define base 137
#define inf 1000000007
#define mod 998244353

const double PI = acos(-1.0);

int n;
LL m;

LL a[N];
LL s[N];

bool check(cint x, cint y) {
	return a[x] * (x - (y - 1)) - (s[x] - s[y - 1]) <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	//
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = n + 1;
		for (int mid; l + 1 < r; ) {
			mid = l + r >> 1;
			if (check(mid, i))
				l = mid;
			else
				r = mid;
		}
		ans = max(ans, l - (i - 1));
	}
	cout << ans << '\n';
	return 0;
}
