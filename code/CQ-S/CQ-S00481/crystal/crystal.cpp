#include <bits/stdc++.h>
using namespace std;

int n, l[500010];
long long m, a[500010], f[500010];

int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	l[0] = 1;
	for (int i = 1; i <= n; i++){
		l[i] = l[i - 1];
		f[i] = f[i - 1] + 1LL * (i - l[i]) * (a[i] - a[i - 1]);
		for (; f[i] > m; l[i]++)
			f[i] -= a[i] - a[l[i]];
		ans = max(ans, i - l[i] + 1); 
	}
	printf ("%d\n", ans);
	return 0;
}
