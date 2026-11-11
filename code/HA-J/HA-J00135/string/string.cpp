#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;
const ll mod = 998244353;
const ll P = 1e9 + 7;
const int N = 2e5 + 5;
int n, a[N];
char c[N];

int main () {
	ios :: sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);

	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	
	ll ans = 0;
	for (int l = 1, r = n; l < r; ) {
		int p = min (a[l], a[r]);
		a[l] -= p;
		a[r] -= p;
		if (c[l] != c[r])
			ans += p;
		if (a[l] == 0)
			l ++;
		if (a[r] == 0)
			r --;
	}
	cout << ans << "\n";
	return 0;
}
