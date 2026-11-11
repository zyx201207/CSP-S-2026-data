#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c;
	cin >> t;
	while(t--) {
		int n, d, a[200002], b[200002], ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= d; j++) {
				for(int k = i; k <= n; k++) {
					if(a[i] + j == a[k] && b[k] == 0) {
						b[k] = 1;
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << endl; 
		ans = 0;
		for(int i = 1; i <= n; i++) a[i] = 0, b[i] = 0;
	}
	return 0;
}

