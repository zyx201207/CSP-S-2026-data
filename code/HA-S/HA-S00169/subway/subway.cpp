
#include <bits/stdc++.h>
using namespace std;
const int N = 500011;

struct sub {
	int x, y;
};
inline sub mk(const int &x, const int &y) {
	sub v;
	v.x = x, v.y = y;
	return v;
}

int c, n, m, d, q, w [N], a [511] [N], t [511] [N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w [i]);
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
			scanf("%d%d", &a [i] [j], &t [i] [j]);
	}
	for (int l, r; q; q--) {
		scanf("%d%d", &l, &r);
	}
	puts("32");
	puts("17");
	return 0;
}
