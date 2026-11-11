#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], l[300005], b[500005], ans[300005];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	if (n >= 5000) {
		for (int i = 1; i <= n; i++) {
			ans[a[i]]++;
		}
		for (int i = 1; i <= m; i++) {
			ans[i] += ans[i - 1];
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			a[i] = b[i];
			if (l[a[i]]) for (int j = l[a[i]]; j < i; j++) l[a[j]] = 0;
			l[a[i]] = i;
		}
		for (int i = 1; i <= m; i++) {
			if (l[i]) ans[i]++;
		}
		memset(l, 0, sizeof l);
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

