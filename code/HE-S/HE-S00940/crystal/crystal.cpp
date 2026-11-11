//Oct31==Dec25?
#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 5e5 + 10;

ll m;
int n, ans;
ll a[N], s[N];

bool check (int l, int r) {
	ll x = a[r] * (r - l + 1) - (s[r] - s[l - 1]);
	if (x <= m) {
		ans = max (ans, r - l + 1);
		return 1;
	}
	return 0;
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int l = i, r = n, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check (i, mid)) l = mid + 1;
			else r = mid - 1;
		}
	} 
	printf ("%d", ans);
	return 0;
}
