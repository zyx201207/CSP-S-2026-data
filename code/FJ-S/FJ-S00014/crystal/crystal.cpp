#include <bits/stdc++.h>
using namespace std;

int const N = 5e5 + 10;

long long a[N], n, m;

bool check(long long mid) {
	long long sum = 0;
	for(int i = 1; i < mid; i++) {
		sum += a[mid] - a[i];
	}
	return sum <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	long long l = 1, r = n;
	while(l <= r) {
		long long mid = (r - l) / 2 + l;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld", l - 1);
	return 0;
}
