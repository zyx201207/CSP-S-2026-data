#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, l, r;
long long ans;
struct node {
	int len;
	char id;
} a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].len);
		getchar();
		a[i].id = getchar();
	}
	l = 1, r = n;
	while (l < r) {
		int x = min(a[l].len, a[r].len);
		if (a[l].id != a[r].id) ans += x;
		a[l].len -= x, a[r].len -= x;
		if (!a[l].len) l++;
		if (!a[r].len) r--;
	}
	printf("%lld", ans);
	return 0;
}
