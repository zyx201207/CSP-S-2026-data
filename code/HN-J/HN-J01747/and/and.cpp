#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int W = 2e5 + 5, INF = (1 << 31) - 1;
int n, m;
ll a[W], ans, sum;
void dfs (int x, int y, ll sum) {
	if (y > m) {
		if (sum != INF) ans = max(sum, ans);
		return ;
	}
	if (x > n) return ;
	dfs(x + 1, y + 1, sum & a[x]);
	dfs(x + 1, y, sum);
}
bool cmp (ll x, ll y) {
	return x > y;
}
int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		if (a[i] == i - 1) cnt++;
	}
	if (cnt == n && n > 2000) {
		ans = INF;
		for (int i = n; i >= n - m + 1; i--) ans &= a[i];
		cout << ans;
		return 0; 
	}
	if (n > 2000) {
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
		return 0;
	}
	dfs(1, 1, INF);
	cout << ans;
	return 0;
} 
