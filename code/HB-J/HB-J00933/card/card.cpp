#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, a[MAXN], ans, cnt[300005], m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		bool k[300005] = {};
		for (int j = i; j <= n; j++)
			k[a[j]] = 1;
		for (int j = 1; j <= m; j++)
			cnt[a[j]] += k[a[j]];
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	return 0;
}
