#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005], js[500005], c[500005];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			a[j] = c[j + i - 1];
		}
		for (int j = i; j <= n; j++) {
			bool f = 0;
			int b;
			for (int k = 1; k <= n; k++) {
				if (f == 1) {
					a[k] = 0;
					continue;
				}
				if (a[k] == c[j]) {
					b = k;
					f = 1;
				}
			}
			if (f == 0) {
				a[++b] = c[j];
			}
		}
		for (int j = 1; j <= n; j++) {
			js[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << js[i] << " ";
	}
	return 0;
}
