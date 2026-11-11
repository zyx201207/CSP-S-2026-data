#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long int m;
long long int a[500005], dp[500005];
long long int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	sort(a, a + n);
	
	for(int i = 0; i < n - 1; i++) dp[i] = a[i + 1] - a[i];
	
	for(int i = 0; i < n - 1; i++) {
		long long int tmp = m, cnt = 0;
		for(int j = i, k = 1; j < n && tmp >= 0; j++, k++) {
			tmp -= dp[j] * k;
			cnt++;
		}
		ans = cnt > ans ? cnt : ans;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
