#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, m;
int a[N];
int f[6010][6010], ans[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			int l = 0;
			f[k][i] = a[i];
			for (int j = 0; j < i; j++) {
				if (f[k][j] == a[i]) {
					l = j;
					break;
				}
			}
			if (l != 0) {
				for (int j = l; j < i; j++) {
					f[k][j] = 0;
				}
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j] == k) ans[k]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
