#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500010], b[500010], t[300010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) a[j] = 0;
		for (int j = i + 1; j <= n; j++) {
			bool f = false;
			if (a[j] == a[i]) {
				f = true;
				for (int k = j; k <= n; k++) {
					a[k] = 0;
				}
			}
			if (f) a[n] = a[i];
			else {
				for (int k = i + 1; k <= n; k++) {
					a[k - 1] = a[k];
				}
				a[n] = a[i];
			}
		}
		for (int j = 1; j <= n; j++) {
			if (a[j] > 0) t[a[j]]++;
		}
		for (int j = 1; j <= n; j++) a[j] = b[j];
	}
	for (int i = 1; i <= m; i++) {
		if (t[i] != 0) cout << t[i] << " ";
	}
	return 0;
}
