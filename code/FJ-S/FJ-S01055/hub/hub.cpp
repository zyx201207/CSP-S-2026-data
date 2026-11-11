// to find the way back home.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = N << 1;
int c, T, n, m, k;

inline bool check(int mid) {
	return m - 4 * (mid - 1) <= k;
}
void subA() {
	while (T--) {
		scanf("%d%d", &n, &k), m = n >> 1;
		for (int i = 1, a, b; i < n; i++) scanf("%d%d", &a, &b);
		if (k == n) { printf("0\n"); continue; }
		if (k >= m) { printf("1\n"); continue; }
		int l = 2, r = m;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}

int p[N];
inline find(int x) { return (p[x] == x) ? x : p[x] = find(p[x]); }
inline bool chk(int S, int i) { return (S >> i) & 1; }
int mp[12][12];
int dis[12][12];

void dfs(int u, int rt) {
	for (int i = 1; i <= n; i++) if (mp[u][i] && !dis[rt][i]) dis[rt][i] = dis[rt][u] + 1, dfs(i, rt);
}

vector<int> pt;
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) mp[i][j] = dis[i][j] = 0;
	for (int i = 1, a, b; i < n; i++) scanf("%d%d", &a, &b), mp[a][b] = mp[b][a] = 1;
	if (n == k) return printf("0\n"), void();
	for (int i = 1; i <= n; i++) dis[i][i] = 1, dfs(i, i);
	
//	for (int i = 1; i <= n; i++, puts(""))
//		for (int j = 1; j <= n; j++) cout << dis[i][j] - 1 << ' ';

	int ans = 0x3f3f3f3f;
	for (int S = 0; S < (1 << n); S++) {
		int cnt = 0; pt.clear();
		for (int i = 0; i < n; i++) if (chk(S, i)) pt.push_back(i + 1);
		if ((int)pt.size() != k) continue;
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i : pt)
			for (int j : pt) if (mp[i][j]) {
				int x = find(i), y = find(j);
				if (x ^ y) p[x] = y, cnt++;
			}
		if (cnt < k - 2) continue;
		
		int res = 0;
		for (int i = 1; i <= n; i++) if (!chk(S, i - 1)) {
			int Min = 0x3f3f3f3f;
			for (int j = 1; j <= n; j++) if (chk(S, j - 1)) Min = min(Min, dis[i][j]);
			res = max(res, Min);
		}
//		cout << "!? " << S << ' ' << cnt << ' ' << res - 1 << endl;
		ans = min(ans, res - 1);
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("hub2.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
//	subA();
	if (c == 13 || c == 14) return subA(), 0;
	while (T--) solve();
	return 0;
}

/*
0 1

5 2
1 2
2 3
3 4
4 5
*/
