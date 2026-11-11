#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1010;
const int inf = 1e9 + 7;
int n, cnt[N];
ll a[N], d, ans, dis[N][N];
bool reach(int x, int y) {
	return a[y] - a[x] <= d;
}
void dfs(int i, int st, int stp) {
	cnt[i]++;
	for (int j = i + 1; j <= n; j++) {
		if (!reach(i, j)) break;
		if (dis[st][j] < stp + 1) continue;
		dfs(j, st, stp + 1);
	}
}

void Main() {
	ll ans = 0;
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (reach(min(i, j), max(i, j))) dis[i][j] = 1;
			else dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt));
		dfs(i, i, 0);
		for (int i = 1; i <= n; i++) {
			ans += (cnt[i] == 2);
		}
//		puts("");
	}
	printf("%d\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int tt, tc;
	scanf("%d%d", &tt, &tc);
	while (tc--) Main();
	return 0;
}
