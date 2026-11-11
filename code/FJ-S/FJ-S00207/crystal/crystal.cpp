#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e5 + 10;
const int MOD = 998244353;
const ll INF = 1e18;
using namespace std;
ll n, m, s, ans, tot, a[N], d[N], sd[N], v[N], sv[N];
bool check(ll x, ll y) {
	ll ret = sv[y] - sv[x - 1] - (x - 1) * (sd[y] - sd[x - 1]);
	return ret <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) d[i] = a[i] - a[i - 1], sd[i] = sd[i - 1] + d[i], v[i] = d[i] * (i - 1), sv[i] = sv[i - 1] + v[i];
	for (int i = 1; i <= n; i++) {
		ll l = i, r = n, tmp = 0;
		while (l <= r) {
			ll mid = l + r >> 1;
			if (check(i, mid)) l = mid + 1, tmp = (mid - i + 1);
			else r = mid - 1;
		}
		ans = max(ans, tmp);
	}
	cout << ans;
	return 0;
}
