#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N];
int lst[M], sum[M];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) lst[a[i]] = i;
	for (int i = 1; i <= n; ++i) {
		if (i - 1 == lst[a[i - 1]]) {
			sum[a[i]] += sum[a[i - 1]] + 1;
		} else ++sum[a[i]];
	}
	for (int i = 1; i < m; ++i) cout << sum[i] << ' ';
	cout << sum[m];
	return 0;
}
