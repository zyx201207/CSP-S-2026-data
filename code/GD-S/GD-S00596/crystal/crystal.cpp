#include <bits/stdc++.h>
using namespace std;

const int T = 5e5 + 5;
long long n,m;
long long a[T];

bool check(long long x) {
	long long sum = 0;
	for (int i = 1;i <= x;i++) {
		sum += a[x] - a[i];
	}
	return sum <= m;
}

int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
	}
	long long l = 1,r = n,mid,ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	printf("%lld",ans - 1);
	return 0;
} 
