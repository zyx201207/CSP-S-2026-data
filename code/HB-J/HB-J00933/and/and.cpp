#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN], n, ans, m;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n - m + 1; i++) {
		int p = a[i];
		for (int j = i + 1; j <= i + m - 1; j++)
			p &= a[j];
		ans = max(ans, p);
	}
	cout << ans << "\n";
	return 0;
}
