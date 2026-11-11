#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+10;
int a[N];
char c[N];

int n;

signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	
	int l = 1, r = n, ans = 0;
	while (true) {
//		printf("l=%lld r=%lld\n", l, r);
		if (a[l] <= 0) l++;
		a[l]--;
		if (a[r] <= 0) r--;
		a[r]--;
		if (l > r) break;
		
		if (c[l] != c[r]) ans++;
	}
	printf("%lld", ans);
	return 0;
}
