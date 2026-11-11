#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;


bool vis[N];
int b[N], a[N];
long long sum[N];
int n, m;
long long id;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for (int j = i; j <= n; j++) {
			a[j] = b[j];
		}
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				for (int x = j - 1; x >= i; x--) {
					if (a[x] == a[j]) {
						a[x] = 0;
						break;
					}
					vis[a[x]] = 0;
					a[x] = 0;
				}
			}
			vis[a[j]] = 1;	

		}
		for (int j = i; j <= n; j++) {
			if (a[j] != 0) {
				sum[a[j]]++;
				
			}
		}
	} 
	for (int i = 1; i <= m; i++) {
		if (sum[i] >= 1) cout << sum[i] << " "; 
	}
	return 0;
}
