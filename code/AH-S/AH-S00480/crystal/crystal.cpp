#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];
queue <int> q;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0, cnt = 1, ans = 1;
	q.push(1);
	for (int i = 2; i <= n; i++) {
		while (!q.empty() && (a[i] - a[i - 1]) * cnt + sum > m) cnt--, sum -= a[i - 1] - a[q.front()], q.pop();
		sum += (a[i] - a[i - 1]) * cnt, cnt++, q.push(i);
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
