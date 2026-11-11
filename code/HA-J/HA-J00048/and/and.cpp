#include <cstdio>
#include <algorithm>

struct andNode {
	int a, d, x;
} ad[200010];

bool cmp (andNode x, andNode y) {
	if (x.d != y.d) return x.d > y.d;
	if (x.x != y.x) return x.x > y.x;
	return x.a > y.a;
}

int n, m, mx = 0, cnt, xcnt;

int main () {
    freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &ad[i].a);
		mx = ad[i].a; cnt = 0;
		while (mx > 0) {
			if (mx % 2 == 1) cnt++;
			xcnt++;
			mx /= 2;
		}
		ad[i].d = cnt; ad[i].x = xcnt;
	}

	std::sort (ad + 1, ad + 1 + n, cmp);
	
	mx = ad[1].a;
	for (int i = 2; i <= m; i++) {
		mx = mx & ad[i].a;
	}
	printf ("%d", mx);
	return 0;
}
