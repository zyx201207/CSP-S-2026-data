#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 5e5 + 10;
ll n, m, ans = 1;
array<ll, N> a;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.begin() + n + 1);
	for(ll r = 1, l = 1, now = 0; r <= n; r++) {
		now += (r - l) * (a[r] - a[r - 1]);
		while(now > m) {
			now -= a[r] - a[l++];
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
}

