#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long m, a[500005], f[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		long long k = (a[i] - a[i - 1]) * (i - 1);
		f[i] = f[i - 1] + k;
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d\n", f[i]-m-i*a[i]+i*a[j]+j*a[i]-j*a[j]);

//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j >= 0; j--) {
//			if (f[i] - f[j] - 1ll*(j-1)*(a[i]-a[j])> m)
//				break;
//			ans = max(ans, i - j + 1);
//		}
//	}

//	for (int i = 1; i <= n; i++)
//		printf("%lld %lld\n", a[i], f[i]);
	for (int i = 1; i <= n; i++) {
//		int p = lower_bound(f + 1, f + i, f[i] - m-(i-j)*()) - f;
		int l = 1, r = i, res = 0;
		while (l <= r) {
			int j = (l + r) / 2;
			if (f[i] - f[j] - 1ll*(j-1)*(a[i]-a[j])<= m) {
				res = i - j + 1;
				r = j - 1;
			}
			else
				l = j + 1;
		}
//		printf("%d %d %d\n", p, i, i - p + 1);
//		f[j-1]>=f[i]-m
//		f[j-1]>=f[i]-m-i*a[i]+i*a[j]+j*a[i]-j*a[j]
//		f[j-1]>=f[i]-m-a[i]*j+a[j]*j+a[i]-a[j]
//		ans = max(ans, i - p + 1);
		ans = max(ans, res);
	}
	printf("%d", ans);
	return 0;
}
/*

8 8 7 3 1 5 7 5 9
1 3 5 5 7 7 8 8 9


*/
