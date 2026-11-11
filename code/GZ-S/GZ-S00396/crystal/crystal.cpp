//GZ-S00396 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5 ;
int n, ma = 1;
ll m, sum[N], a[N];
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	sort (a + 1, a + 1 + n);
	for (int i = 1, l = 1; i < n; i++) sum[i] = sum[i - 1] + a[i + 1] - a[i], (sum[i] - sum[l - 1] <= m ? ma = i - l + 2 : l++);
	printf ("%d", ma);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
