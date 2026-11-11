//GZ-J00625 罗思妤 北京师范大学贵阳附属中学 
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, t;
map <int, int> a;
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	if (n == m) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &t);
			a[t] = i;
		}
		for (int i = 1; i <= n; i++) printf ("%d ", a[i]);
		return 0;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
