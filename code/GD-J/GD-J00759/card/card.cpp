#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], b[N], c[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		fill(b + 1, b + 1 + n, 0);
		for (int j = i; j <= n; j++) {
			if (b[a[j]]) {
				for (int k = b[a[j]]; k <= j; k++) {
					b[a[k]] = 0;
				}
			}
			b[a[j]] = j;
		}
		for (int j = 1; j <= m; j++) {
			if (b[j]) c[j]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	cout << '\n';
	return 0;
}
