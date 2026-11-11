#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;

int n, sum, ans = 1;
ll tmp, m, a[N];

int main () {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf ("%d%lld", &n, &m);
	for (int i = 1;i <= n;++i) scanf ("%lld", &a[i]);
	
	sort (a + 1, a + n + 1);
	
	if (n <= 5000) {
		
		for (int i = 2;i <= n;++i) {
			tmp = 0, sum = 1;
			for (int j = i - 1;j >= 1;--j)
				if (tmp + a[i] - a[j] <= m)
					++sum, tmp += a[i] - a[j];
			ans = max(ans, sum);
		}
	} else {
		for (int i = n - 1;i >= 1;--i)
			if (tmp += a[n] - a[i])
				tmp += a[n] - a[i], ++ans;
	}
	
	
	printf ("%d\n", ans);
	
	return 0;
} 
