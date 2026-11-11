#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n, m, a[N], b[N], ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	for (ll i = 2, cnt, l, r; i <= n; i++) {
		cnt = 1;
		while (i + cnt - 1 <= n && a[i + cnt - 1] == a[i]) cnt++;
		cnt--;
		l = 1, r = i - 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid) - (b[i - 1] - b[mid - 1]) <= m) r = mid - 1;
			else l = mid + 1;
		}
		if (l < i) ans = max(ans, i - l + cnt);
	}
	printf("%lld", ans);
	return 0;
}
