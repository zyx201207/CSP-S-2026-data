#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, p = 998244353; typedef long long ll;
int c, t, n, g[N], nxt[N], pre[N], box[N]; unsigned int f[N]; ll d, x[N];
int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--) {
		scanf("%d%lld", &n, &d); for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		if(n == 1) { printf("0\n"); continue ; }
		if(c == 11 || c == 12) {
			ll D = x[2] - x[1]; ll cnt = d / D; if(cnt == 0) { printf("0\n"); continue ; }
			long long ans = 0;
			for(int i = 1; i < n; i++)
				if(i % cnt == cnt - 1 && i > cnt && i < 2 * cnt) ans += (n - i);
			printf("%lld\n", ans);
			continue ;
		}
		else if(c == 13 || c == 14) {
			int l = n + 1, r = 0; for(int i = 1; i <= n; i++) if(x[i] - x[1] <= d && x[n] - x[i] <= d) l = min(l, i), r = i;
			ll ans = 0;
			for(int i = 1; i < l; i++) nxt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
			for(int i = r + 1; i <= n; i++) pre[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
			for(int i = 1; i <= n; i++) box[i] = 0;
			for(int i = 1; i < l; i++) box[nxt[i]]++;
			for(int i = r + 1; i <= n; i++) ans += box[pre[i]];
			printf("%lld\n", ans);
			continue ;
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) f[j] = 0, g[j] = INT_MAX;
			f[i] = 1, g[i] = 1; int l = i, len = 1; unsigned int sum = 1;
			// printf("start:%d\n", i);
			for(int j = i + 1; j <= n; j++) {
				// printf("i:%d j:%d l:%d\n", i, j, l);
				while(l < j && x[j] - x[l] > d) sum -= f[l], l++;
				if(l == j) break;
				if(g[l] != len) {
					sum = f[l], len = g[l]; int k = l; while(k + 1 < j && g[k+1] == g[l]) sum += f[++k];
				}
				f[j] = sum, g[j] = len + 1;
				// printf("j:%d l:%d sum:%d f:%d g:%d\n", j, l, sum, f[j], g[j]);
			}
			for(int j = i + 1; j <= n; j++) if(f[j] == 2) ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}