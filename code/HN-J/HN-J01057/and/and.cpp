#include<iostream>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int n, m;
ll a[MAXN], ans;
void dfs(int dep, ll sum, int last) {
	if (dep > m) {
		ans = max(ans, sum);
		return;
	}
	for (int i = last + 1; i <= n; i ++) dfs(dep + 1, sum & a[i], i);
	return;
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (m == n) {//7 m = n
		ans = a[1];
		for (int i = 2; i <= n; i ++) ans &= a[i];
		cout << ans;
		return 0;
	} else if (n - 1 == m) {//11, 12 m = n - 1
		ans = a[2];
		for (int i = 3; i <= n; i ++) ans &= a[i];
		ll ans2 = a[1];
		for (int i = 2; i < n; i ++) ans2 &= a[i];
		cout << max(ans, ans2);
		return 0;
	}
	for (int i = 1; i <= n; i ++) dfs(2, a[i], i);
	cout << ans;
	return 0;
} 

