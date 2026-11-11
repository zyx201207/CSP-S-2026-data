#include<cstdio>
#include<algorithm>
using LL = long long;
const int N = 5e5 + 5;
int n;
LL m;
LL s[N];
LL a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	int j = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (a[i] * (i - j + 1) - (s[i] - s[j - 1]) > m)
			++j;
		ans = std::max(ans, i - j + 1);
	}
	printf("%d\n", ans);
	return 0;
}