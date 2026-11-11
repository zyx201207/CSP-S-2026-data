//GZ-S00267 贵阳华师一 冯子尧 
#include <bits/stdc++.h>
#define upp(a, x, y) for (int a = x; a <= y; a++)
#define dww(a, x, y) for (int a = x; a >= y; a--)
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef pair<LL, LL> PLL;

const int N = 2e6 + 10;

int c, t;
int n;
LL d;
LL x[N];
int ft[N], gt[N];

void solve() {
	scanf("%d%lld", &n, &d);
	upp(i, 1, n) scanf("%lld", &x[i]);
	int back = 1;
	x[n + 1] = x[n] + d + 1;
	upp(i, 1, n) {
		while (1) {
			if (x[back + 1] - x[i] > d || back + 1 == n + 1) break;
			back++;
		}
		ft[i] = back;
		gt[back] = i;
	}
	upp(i, 1, n) {
		if (gt[i]) break;
		gt[i] = 1;
	}
	int times;
	LL res = 0;
	upp(i, 2, n) {
		if (ft[i] - x[i] == 2) {
			times = 0;
			int j = i;
			while (1) {
				j = gt[j];
				times++;
				if (gt[j] == j) break;
			}
			res += times;
		}
	}
	printf("%lld\n", res);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		solve();
	} 
	return 0;
}
