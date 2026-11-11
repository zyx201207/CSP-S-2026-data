// difficulty: yellow / *1400
// tags: greedy
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200010], ans;
void chk(int x) {
	int c = ans | (1LL << x), cnt = 0;
	for (int i = 1; i <= n; i++) if ((a[i] & c) == c) cnt++;
	if (cnt >= m) ans = c;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 32; i >= 0; i--) chk(i);
	cout << ans;
	return 0;
}
