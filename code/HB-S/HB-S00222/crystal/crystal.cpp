#include <bits/stdc++.h>

using namespace std;
const long long N = 5e5 + 5;
long long n , m , a[N] , sum[N];
long long ans = 0;
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	scanf("%lld %lld" , & n , & m);
	for(long long i = 1 ; i <= n ; ++ i) {
		scanf("%lld" , & a[i]);
	}
	sort(a + 1 , a + 1 + n);
	for(long long i = 1 ; i <= n ; ++ i) {
		sum[i] = sum[i - 1] + a[i];
	}
	for(long long i = 1 ; i <= n ; ++ i) {
		long long l = 1 , r = i - 1 , mid , pos = 0;
		while(l <= r) {
			mid = (l + r + 1) / 2;
			if((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) {
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans , i - pos + 1);
	}
	printf("%lld" , ans);
	return 0;
}
