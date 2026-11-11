#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
long long a[N], n, m, lst[N], ans[N], cnt, d[N];
vector<int> G[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = n; i; i --) {
		if (!lst[a[i]])
			G[i].push_back(i + 1), lst[a[i]] = i + 1;
		else
			G[i].push_back(lst[a[i]]);
	}
	for (int i = 1; i <= n; i ++) {
		d[i] += 1;
		for (auto j : G[i])
			d[j] += d[i];
		ans[a[i]] += d[i];
	}
	for (int i = 1; i <= m; i ++) {
		cout << ans[i];
		if (i != m) cout << " ";
	}
	return 0;
}
