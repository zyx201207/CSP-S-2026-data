#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2000005;

ll a[N], nxt[N], f[N], g[N], s[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, T;
	cin >> c >> T;
	while (T--) {
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n;  i++) {
			cin >> a[i];
		}
		ll ans = 0;
		for (int i = n, j = n; i >= 1; i--) {
			while (a[j] - a[i] > d) j--;
			nxt[i] = j;
		}
//		if (n <= 5000) {
//			for (int i = 1; i <= n; i++) {
//				s[i + 1] = 0;
//				ll sum = 1;
//				f[i] = s[i] = 1;
//				for (int j = i - 1; j >= 1; j--) {
//					f[j] = min(sum - s[min(1ll * i, nxt[j]) + 1], 3ll);
//					sum += f[j];
//					s[j] = sum;
//				}
//				for (int j = 1; j <= i; j++) {
//					printf("%d ", f[j]);
//					ans += f[j] == 2;
//				}
//				printf("\n");
//			}
//		}
//		
//		cout << ans << "\n"; 
//		exit(0);
		for (int i = n; i >= 2; i--) {
			if (nxt[i] == i) {
				f[i] = 0;
				continue;	
			}
			if (nxt[i] == nxt[i - 1]) f[i] = 0;
			else f[i] = nxt[i] - nxt[i - 1] + f[nxt[i]];
		}
//		for (int i = 1; i <= n; i++) {
//			printf("%d ", nxt[i]);
//		}
//		printf("\n");
//		printf("f: ");
//		for (int i = 1; i <= n; i++) {
//			printf("%d ", f[i]);
//		}
//		printf("\n");
		for (int i = n; i >= 1; i--) {
			if (nxt[i] == i) {
				g[i] = 0;
				continue;	
			}
			
			if (nxt[i] == i + 1) g[i] = g[nxt[i]];
			else {
				ll d1 = nxt[nxt[i] - 1];
				ll d2 = nxt[nxt[i] - 2];
//				if (i == 2) {
//					printf("%d %d\n", d1, d2);
//				}
				if (d2 == nxt[nxt[i]]) { 
					g[i] = 0;
					continue;
				}
				if (d1 == nxt[nxt[i]]) {
					g[i] = f[nxt[i]] + d1 - d2;
				} else if (d2 == nxt[nxt[i]] - 1) {
					assert(d1 == d2);
					g[i] = g[nxt[i]];
				} else if (d1 == nxt[nxt[i]] - 1) {
					g[i] = g[nxt[i]] + d1 - d2;
				} else {
					g[i] = g[nxt[i]] + d1 - d2;
				}
			} 
			ans += g[i]; 
		}
//		for (int i = 1; i <= n; i++) {
//			printf("%d ", g[i]);
//		}
//		printf("\n");
		cout << ans << "\n";
	}
	return 0;
}
