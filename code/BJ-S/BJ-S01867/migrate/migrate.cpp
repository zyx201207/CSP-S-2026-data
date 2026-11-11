

#include <bits/stdc++.h>

using namespace std;

long long c,q;
long long n = 0,m = 0;
long long a[500009];

int main () {
	
	freopen("migrate.in", "r",stdin);
	freopen("migrate.out", "w",stdout);
	
	cin >> c >> q;
	for (int i = 1; i <= q; i++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c==11||c==12) {
			long long gongcha = a[2]-a[1];
			long long x = m/gongcha;
			long long sum = 0;
			//for (int i = 1; i < x; i++) {
			long long y = x+x-1;
			long long kongge = n-1;
				//if (y>kongge) {
				//	continue;
				//}
			sum += kongge-y+1;
			if (sum<=0) {
				sum = 0;
			}
			//}
			cout << sum << endl;
		}
		if (c==13||c==14) {
			int ans = 0;
			int X = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i]-m<=a[1]&&a[i]+m>=a[n]) {
					X = i;
				}
			}
			for (int i = 1; i <= X-1; i++) {
				for (int j = X+1; j <= n; j++) {
					if (a[j]-a[i]<=m) {
						continue;
					}
					if (a[j]-a[X-1]<=m&&a[j]-a[X-2]>m) {
						ans++;
					}
				}
			}
			cout << ans << endl;
		
		}
	}
	
	return 0;
}
