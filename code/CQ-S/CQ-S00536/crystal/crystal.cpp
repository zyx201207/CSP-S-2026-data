#include <bits/stdc++.h>
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n;
ll m, a[N], sum[N]; 
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1, l = 1; i <= n; ++i) {
		while(a[i] * (i - l + 1) - (sum[i] - sum[l - 1]) > m) ++l;
		cmax(ans, i - l + 1);
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
} 
