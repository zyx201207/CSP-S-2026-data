#include <cstdio>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
using namespace std;
typedef long long ll;
ll a[500010];
int n, m;
int ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep (i, 1, n) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 1;
	ll t = 0;
	ans = 1;
	rep (i, 2, n) {
		int c = a[i] - a[i - 1];
		t += c * (i - l);
		while (t > m && l <= i) {
			t -= a[i] - a[l];
			l++;
		}
		int len = i - l + 1;
		ans = ans > len ? ans : len;
	}
	printf("%d", ans);
	return 0;
}
