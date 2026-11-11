#include <bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = (s << 1) + (s << 3) + ch - 48;
	return s * w;
}
const int N = 500005;
int n, m, a[N], s[N], ans; 
signed main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	n = rd(), m = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 1, j = 1, sum = 0; i <= n; i++){
		for (; j < i && sum > m; j++) sum -= a[i] - a[j];
		if (sum <= m) ans = max(ans, i - j + 1);
		sum += (a[i + 1] - a[i]) * (i - j + 1);
	}
	printf ("%lld\n", ans);
	return 0;
}

