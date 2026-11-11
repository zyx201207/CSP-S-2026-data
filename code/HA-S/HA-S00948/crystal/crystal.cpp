#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
int n;
ll a[N], s[N], m;
bool check(int k) {
	ll l, r, w, rest;
	for (int i = 1; i <= n - k + 1; i++) {
		l = i, r = i + k - 1;
		w = a[r], rest = 0;
		rest += a[r] * (r - l) - (s[r - 1] - s[l - 1]);
		if (rest <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int L = 1, R = n, mid;
	while (L < R) {
		mid = (L + R + 1) >> 1;
		if (check(mid)) L = mid;
		else R = mid - 1;
	}
	cout << L << '\n';
	return 0;
}