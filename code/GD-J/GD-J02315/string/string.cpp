#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
struct Node {
	int a;
	char c;
} d[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %c", &d[i].a, &d[i].c);
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		int maxn = min(d[l].a, d[r].a);
		if (d[l].c != d[r].c)
			ans += maxn;
		d[l].a -= maxn;
		d[r].a -= maxn;
		if (d[l].a == 0)
			l++;
		if (d[r].a == 0)
			r--;
	}
	printf("%lld", ans);
	return 0;
}
