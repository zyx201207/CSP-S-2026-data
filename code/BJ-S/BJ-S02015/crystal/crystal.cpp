// 原来是双指针
#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define dbg(x) ({auto __V = (x); cout << __V << endl; __V;})
#define dbg_end(x, S) ({auto __V = (x); cout << __V << (S); __V;})
#else
#define dbg(x) x
#define dbg_end(x, S) x
#endif

#define ll long long
#define ull unsigned long long
const int MAXN = 500005;

ull m;
int n, ans = 0;
ll a[MAXN];
ll sum[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%llu", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = 1; // []
	for (; r <= n; r++) {
		ll lrsum = sum[r] - sum[l - 1];
		if ((a[r] * (r - l + 1) - lrsum) > m)
			l++;
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}
