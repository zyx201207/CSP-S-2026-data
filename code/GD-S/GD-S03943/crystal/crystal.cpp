#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 7;
ll a[N];
ll n, m, suml, sumr, ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	sumr = a[1];
	for (ll l = 0, r = 1; r <= n; ++r, sumr += a[r]) {
		while (a[r] * (r - l) - sumr + suml > m) ++l, suml += a[l];
		ans = max(ans, r - l);
	}
	cout << ans;
	return 0;
} 
