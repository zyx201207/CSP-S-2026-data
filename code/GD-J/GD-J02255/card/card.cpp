#include <bits/stdc++.h>
using namespace std;


int n, m, p;
int a[500010];
int r[300010];
int cnt[300010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		if (!r[a[i]]) {
			r[a[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			j = r[a[j]];
			cnt[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
