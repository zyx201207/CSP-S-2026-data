#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace::std;
const int N = 5e5 + 10;
const long double eps = 1e-9;
long long a[N];
long long d[N];
__int128_t s1[N], s2[N];
int n;
long long m;
bool cmp(long long a, long long b) {
	return a < b;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	long long dd = 0;
	bool tttt = 1, f = 1;
	for(int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		if(tttt) { dd = d[i]; tttt = 0; }
		if(d[i] != dd) { f = 0; }
	}
	if(f) {
		long long ans = ((long double)1.0 + sqrt((long double)1.0 + (long double)8.0 * m / dd)) / 2;
		printf("%lld\n", min(ans, (long long)n));
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
//	for(int i = 1; i <= n; i++) printf("%lld ", d[i]);
//	printf("\n");
	for(int i = 1; i <= n; i++) {
		s1[i] = s1[i - 1] + (__int128_t)(i - 1) * d[i];
		s2[i] = s2[i - 1] + d[i];
	}
//	for(int i = 1; i <= n; i++) printf("%lld ", s1[i]);
//	printf("\n");
//	for(int i = 1; i <= n; i++) printf("%lld ", s2[i]);	
//	printf("\n");
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			long long dis = s1[j] - s1[i] - (__int128_t)(i - 1) * (s2[j] - s2[i]);
			if(dis <= m) {
//				if(j - i + 1 >= ans) cout << i << " " << j << " " << dis << endl;
				ans = max(ans, (long long)j - i + 1);
			}
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
