#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll n, m, a[N], ans {-1};
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i {1}; i <= n; ++i) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + 1 + n);
	for (int i {2}; i <= n; ++i) {
		ll k = m, cnt {1};
		for (int j = i - 1; j >= 1; --j) {
			if (k - (a[i] - a[j]) >= 0) {
				k = k - (a[i] - a[j]);
				++cnt;
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
	return 0;
}
