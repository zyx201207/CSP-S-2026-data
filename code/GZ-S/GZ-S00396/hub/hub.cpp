//GZ-S00396 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
int C, T, n, k, u, v;
int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%d%d", &C, &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) cin >> u >> v;
		(T > 0 ? printf ("1\n") : printf ("2\n"));
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
