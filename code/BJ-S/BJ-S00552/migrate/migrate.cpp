//40 pts
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
const ll PInf = 0x3f3f3f3f3f3f3f3f;
const int MaxN = 5e3;

int c, t;
int n; ll d;
ll x[1 + MaxN];
ll dis[1 + MaxN][1 + MaxN]; int cnt[1 + MaxN][1 + MaxN];
ll ans;

void work_t () {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i) {scanf("%lld", &x[i]);}
	for (int l = 1; l <= n; ++l) {for (int r = 1; r <= n; ++r) {
		dis[l][r] = ((l == r) ?(0) :(PInf));
		cnt[l][r] = ((l == r) ?(1) :(0));
	}}
	ans = 0;
	for (int len = 2; len <= n; ++len) {for (int l = 1; l + len - 1 <= n; ++l) {
		int r = l + len - 1, mid = min(int(upper_bound(&x[1], &x[n] + 1, x[l] + d) - x) - 1, r);
		dis[l][r] = min(dis[l][r], 1 + dis[mid][r]);
		cnt[l][r] = cnt[mid][r];
		if (dis[l][r] == PInf || cnt[l][r] == 3) {continue;}
		if (mid > l + 2 && dis[mid - 2][r] == dis[mid][r]) {continue;}
		if (mid > l + 1 && dis[mid - 1][r] == dis[mid][r]) {
			cnt[l][r] = min(3, cnt[l][r] + cnt[mid - 1][r]);
		}
		if (cnt[l][r] == 2) {++ans;}
	}}
	// for (int l = 1; l <= n; ++l) {
	// 	for (int r = l + 1; r <= n; ++r) {
	// 		printf("[%lld %d] ", dis[l][r], cnt[l][r]);
	// 	}
	// 	printf("\n");
	// }
	printf("%lld\n", ans);
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {work_t();}
	return 0;
}