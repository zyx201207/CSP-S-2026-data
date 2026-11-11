#include <bits/stdc++.h> 
using namespace std;

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	long long c, t;
	cin >> c >> t;
	
	while (t--) {
		long long n, d;
		cin >> n >> d;
		long long a[n + 1];
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		long long ans = 0;
		sort (a + 1, a + n + 1);
		
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				long long path = 0;
				for (long long k = 1; k <= j; k++) {
					if ((a[k] - a[i]) <= d && (a[j] - a[k]) <= d) {
						path++;
					}
				}
				if (path == 2) ans++;
			}
		}
		cout << ans - 1 << endl;
	}
	
	return 0;
}
