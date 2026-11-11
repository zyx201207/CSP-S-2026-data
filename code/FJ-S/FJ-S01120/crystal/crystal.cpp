#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500000 + 5000;
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	ll ans = 0;
	int zans = 1;
	for (int i = 2; i <= n; i++) {
		ans += 1ll * (i - l) * (a[i] - a[i - 1]);
		while (ans > m) {
			ans -= a[i] - a[l];
			l++;
		}
		zans = max(zans, i - l + 1);
	}
	cout << zans << endl;
	return 0;
}
