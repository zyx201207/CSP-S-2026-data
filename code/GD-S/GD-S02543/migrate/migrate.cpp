#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 5;
ll c, T, n, d, x[N], to[N], suf1[N], sel1[N], suf2[N], sel2[N], ans;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &T);
	while (T--) {
		scanf("%lld %lld", &n, &d);
		for (ll i = 0; i <= n + 1; i++) x[i] = 0;
		for (ll i = 0; i <= n + 1; i++) to[i] = 0;
		for (ll i = 0; i <= n + 1; i++) suf1[i] = 0;
		for (ll i = 0; i <= n + 1; i++) sel1[i] = 0;
		for (ll i = 0; i <= n + 1; i++) suf2[i] = 0;
		for (ll i = 0; i <= n + 1; i++) sel2[i] = 0;
		ans = 0;
		for (ll i = 1; i <= n; i++) scanf("%lld", x + i);
		for (ll i = 1; i <= n; i++) to[i] = upper_bound(x + i, x + n + 1, x[i] + d) - x - 1;
		for (ll i = n - 1; i; i--) {
			if (to[i] == i) continue;
			sel1[i] = to[i] - i;
			suf1[i] = suf1[to[i]] + to[to[i]] - to[to[i] - 1];
			if (to[i] == i + 1) suf2[i] = sel2[to[i]] + suf2[to[i]];
			else {
				if (to[i] == i + 2) sel2[i] = to[to[i] - 1] - to[i] + suf1[to[to[i] - 1]] + to[to[to[i] - 1]] - to[to[to[i] - 1] - 1];
				else {
					sel2[i] = to[to[i] - 1] - to[to[i] - 2];
					if (sel2[i]) sel2[i] += suf1[to[to[i] - 1]] + to[to[to[i] - 1]] - to[to[to[i] - 1] - 1]; 
				}
				if (to[to[i] - 1] == to[to[i]] - 1) suf2[i] = suf2[to[i]];
				else if (to[to[i] - 1] < to[to[i]] - 1) suf2[i] = sel2[to[i]] + suf2[to[i]];
			}
			ans += sel2[i] + suf2[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
