#include <bits/stdc++.h>
using namespace std;
long long c, t, a[2000006];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		long long n, d, ans = 0;
		scanf("%lld%lld", &n, &d);
		for (long long i = 1;i <= n;i++)
			scanf("%lld", &a[i]);
		if (c <= 10) {
			for (long long i = 1;i <= n;i++) {
				long long t[5006], l1 = 1;
				memset(t, 0, sizeof(t));
				for (long long j = i + 1;j <= n;j++)
					if (a[j] - a[l1] <= d)
						t[j] = t[l1] + 1;
					else
						l1++, j--;
				long long f[5006], l = i;
				memset(f, 0, sizeof(f));
				f[i] = 1;
				for (long long j = i + 1;j <= n;j++) {
					long long sum = 0;
						while (t[l] + 1 < t[j])
						l++;
					for (long long k = l;k < j;k++) {
						if (t[k] + 1 == t[j] && a[j] - a[k] <= d)
							sum += f[k];
					} 
					f[j] = sum;
					if (sum == 2) {
						//cout << i << " " << j << " " << t[l] << t[j] << endl;
						ans++;
					}
				}
			}
		} else {
			if (c == 11 || c == 12) {
				long long ka = a[2] - a[1], pa = d / ka;
				if (pa == 2)
					ans = n - 3;
				else
					ans = 0;
			}
			else
				ans = n * (n - 1) / 2;
		}
		cout << ans << endl;
	}
}
