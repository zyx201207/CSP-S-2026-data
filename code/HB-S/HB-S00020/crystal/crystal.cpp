#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+10;
int a[N], pre[N];

int n, m, ans = 0;

bool A () {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i)
			return false;
	}
	return true;
}
bool B () {
	for (int i = 2; i <= n; i++) {
		if (a[i]-a[i-1] != a[2]-a[1])
			return false;
	}
	return true;
}

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld%lld", &n, &m);
	pre[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i] = pre[i-1]+a[i];
	}
	sort(a+1, a+n+1);
	
	if (A()) {
		ans = m+1;
		printf("%lld", ans);
	}
	else if (B()) {
		int gongcha = a[2]-a[1];
		ans = m/gongcha+1;
		printf("%lld", ans);
	}
	else {
		for (int i = 2; i <= n; i++) {
			int sum = (i-1)*a[i]-pre[i-1];
			if (sum <= m)
				ans = i;
			else
				break;
		}
		printf("%lld", ans);
	}
	return 0;
}
