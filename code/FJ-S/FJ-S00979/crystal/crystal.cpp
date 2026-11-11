#include <bits/stdc++.h>
#define sum(l, r) (pre[r] - pre[l - 1])
using namespace std;
const int N = 1000010;
long long n, m, a[N], ans, sum, pre[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] + a[i];
	for (long long l = 1, r = 1; r <= n; l ++) {
		while (r <= n && a[r] * (r - l + 1) - sum(l, r) <= m)
			r ++;
		ans = max(ans, r - l);		
	}
	cout << ans;
	return 0;
}

