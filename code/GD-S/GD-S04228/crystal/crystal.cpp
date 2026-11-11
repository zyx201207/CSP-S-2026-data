#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
const int N = 500005;
using namespace std;

int n, m;
int a[N], pre[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1, l = 1;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		while (a[i] * (i - l + 1) - (pre[i] - pre[l - 1]) > m)
			l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
