#include<bits/stdc++.h>
using namespace std;
long long c, t, n, d, ans = 0;
long long a[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(long long t1 = 1; t1 <= t; t1++) {
		ans = 0;
		cin >> n >> d;
		for(long long i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(long long i = 1; i <= n - 3; i++) {
			long long j = i + 3;
			if(a[i + 2] - a[i] <= d && a[j] - a[j - 2] <= d && a[j] - a[i] > d) {
				ans++;
			}
		}
		cout << ans <<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
