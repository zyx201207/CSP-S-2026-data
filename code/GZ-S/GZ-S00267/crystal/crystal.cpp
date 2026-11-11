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

const int N = 5e5 + 10;

int n;
LL m;
LL a[N], f[N];
int ans;

bool check(int l, int r) {
	return f[r] - f[l - 1] + m >= (r - l + 1) * a[r];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	upp(i, 1, n) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	upp(i, 1, n) f[i] = f[i - 1] + a[i];
	upp(i, 1, n) {
		int l = 1, r = i;
		while (l < r) {
			int mid = l + r >> 1;
			if (check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	printf("%d", ans);
	return 0;
}
