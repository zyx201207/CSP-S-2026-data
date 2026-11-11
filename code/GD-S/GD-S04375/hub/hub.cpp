#include <bits/stdc++.h>

using namespace std;

#define N 10005
#define M 2000005
#define coi const int &

int n, k;
int tot, to[M], nxt[M], lst[N];
int mxd[N], dp[N][N];

void clear_edge() {
	tot = 0;
	fill(to, to + M, 0);
	fill(nxt, nxt + M, 0);
	fill(lst, lst + M, 0);
}
void add_edge(coi u, coi v) {
	to[++ tot] = v;
	nxt[tot] = lst[u];
	lst[u] = tot;
}
void DP(coi u, coi fa) {
	int ch_cnt = 0;
	for (int i = lst[u], v; v = to[i], i; i = nxt[i]) {
		if (! (v ^ fa)) {
			continue ;
		}
		++ ch_cnt;
		DP(v, u);
		dp[0][u] = mxd[v] + 1;
		for (int j = 1; j <= k; ++ j) {
			dp[j][u] = min({dp[j][u], max(dp[j - 1][v], mxd[u]), max(dp[j][v], mxd[u] + 1)});
			for (int p = 0; p <= j; ++ p) {
				dp[j][u] = min({dp[j][u], max(dp[p][u], dp[j - p][v])});
			}
			
		}
		mxd[u] = max(mxd[u], mxd[v] + 1);
	}
	if (! ch_cnt) {
		mxd[u] = 0;
		dp[0][u] = dp[1][u] = 0;
	}
}
void solve() {
	clear_edge();
	scanf("%d%d", & n, & k);
	for (int i = 1, u, v; i < n; ++ i) {
		scanf("%d%d", & u, & v);
		add_edge(u, v), add_edge(v, u);
	}
	for (int i = 0; i <= k; ++ i) {
		fill(dp[i], dp[i] + 1 + n, N);
	}
	fill(mxd, mxd + 1 + n, 0);
	DP(1, 0);
	printf("%d\n", dp[k][1]);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", & c, & t);
	while (t --) {
		solve();
	}
	return 0;
}
