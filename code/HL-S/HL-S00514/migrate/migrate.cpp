#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e6 + 100;

typedef long long ll;

int c, T;
ll n, d, X[N], cnt[N], cnt3[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> T;
	while (T -- ) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++ ) cin >> X[i];
		for (int i = 1; i <= n; i ++ ) cnt[i] = 0, cnt3[i] = 0;
/*
		for (int i = n; i >= 1; i -- ) {
			int p = upper_bound(X + 1, X + n + 1, X[i] + d) - X - 1;
			if (p > i) cnt3[i] = cnt3[p] + 1;
		}
*/
		ll ans = 0;
		for (int i = 1; i <= n - 3; i ++ ) {
			int p = upper_bound(X + 1, X + n + 1, X[i] + d) - X - 1;
			cnt[p] ++ ;
			if (p - i >= 2) {
				int p2 = upper_bound(X + 1, X + n + 1, X[p - 1] + d) - X - 1;
				int p3 = upper_bound(X + 1, X + n + 1, X[p - 2] + d) - X - 1;
				ll cnt2 = p2 - p3;
				ans += (cnt[i] + 1) * (cnt2 + cnt3[p2]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
