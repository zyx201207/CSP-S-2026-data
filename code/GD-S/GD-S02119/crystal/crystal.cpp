#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 7;
ll a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n; ll m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll sum = 0;
	ll l = 1, ans = 0;
	for(ll i = 1; i <= n; i++) {
		sum += a[i];
		while((i - l + 1) * a[i] - sum > m) sum -= a[l], l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	return 0;
}
