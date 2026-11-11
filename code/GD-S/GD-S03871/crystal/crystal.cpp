#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 5e5 + 9;
int n, m, ans, a[MAXN];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int r = 1, l = 1, pre = 0; r <= n; r++) {
		pre += a[r];
		while(l < r && a[r] * (r - l + 1) - pre > m) {
			pre -= a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
