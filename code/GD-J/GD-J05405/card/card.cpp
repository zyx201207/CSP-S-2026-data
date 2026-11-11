#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], lst[M], cnt[N], ans[M];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) cnt[lst[a[i]]]++;
	for (int i = 1; i <= n; i++)
		if (cnt != 0) {
			if (i == lst[a[i]]) {
				ans[a[i]] += cnt[i];
				cnt[i + 1] += cnt[i];
			} else {
				cnt[lst[a[i]]] += cnt[i];
			}
		}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
