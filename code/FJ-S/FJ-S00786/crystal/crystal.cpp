#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], ans;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int j = 1, tot = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		tot += sum * (a[i] - a[i - 1]), sum++;
		while (tot > m && j <= i)
			tot -= (a[i] - a[j]), j++, sum--;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}
