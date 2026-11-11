#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, m, a[N];
ll s[N];
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i]; 
	}
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) s[i] = s[i - 1] + a[i];
	ll l = 1, res = 1;
	for (int r = 2; r <= n; ++ r) {
		while (l < r && (r - l + 1) * a[r] - (s[r] - s[l - 1]) > m) l ++;
		res = max (res, r - l + 1);
	}
	cout << res << '\n';
	return 0;
} 
