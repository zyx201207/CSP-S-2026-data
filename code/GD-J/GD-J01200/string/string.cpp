#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N = 2e5 + 10;
ll a[N], ans, s[N], n;
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s[i] = a[i] + s[i - 1];
	}
	ll l = 1, r = n, ls = 0, rs = s[n];
	while (l < r) {
	while (c[l] == c[r]) {
		if (s[l] - ls > rs - s[r - 1]) ls += (rs - s[r - 1]), rs = s[r - 1], r--;
		else rs -= (s[l] - ls), ls = s[l], l++; 
	}
		if (s[l] - ls > rs - s[r - 1]) ans += (rs - s[r - 1]), ls += (rs - s[r - 1]), rs = s[r - 1], r--;
		else ans += (s[l] - ls), rs -= (s[l] - ls), ls = s[l], l++;
	}
	cout << ans;
	return 0;
}

