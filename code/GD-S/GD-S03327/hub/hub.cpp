#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 1e6 + 5;
namespace taskA {
	void solve() {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) scanf("%*d%*d");
		int m = (n - 1) >> 1, ans;
		if (k == n) ans = 0;
		else {
			ans = (m + 5) / 4; int o = (m + 1) % 4;
			for (int i = 3; i <= k; i++) {
				if (ans == 1) break;
				if (o == 0) ans--;
				o = (o + 3) % 4;
			}
		}
		printf("%d\n", ans);
	}
}
struct Edge {int now, nxt;} e[N << 1]; int head[N], cur;
void add(int u, int v) {e[++cur].now = v, e[cur].nxt = head[u], head[u] = cur;}
int n, k, dis[4005][4005], mxd[N], cnt[N], D;
void dfs1(int u, int fa) {
	mxd[u] = cnt[u] = 0;
	for (int i = head[u], v; i; i = e[i].nxt) if ((v = e[i].now) != fa) dfs1(v, u), mxd[u] = max(mxd[u], mxd[v] + 1), cnt[u] += cnt[v];
	cnt[u] += (mxd[u] >= D);
}
void dfs2(int u, int fa, int rt) {
	dis[rt][u] = dis[rt][fa] + 1; for (int i = head[u], v; i; i = e[i].nxt) if ((v = e[i].now) != fa) dfs2(v, u, rt);
}
int tot, tmx[N];
void dfs3(int u, int fa, int ban) {
	if (tot > k) return; tmx[u] = (dis[ban][u] > D ? 0 : -(int)1e9); if (u == ban) return;
	for (int i = head[u], v; i; i = e[i].nxt) if ((v = e[i].now) != fa) dfs3(v, u, ban), tmx[u] = max(tmx[u], tmx[v] + 1);
	tot += (tmx[u] >= D);
}
bool check(int MD) {
	D = MD;
	for (int x = 1; x <= n; x++) {
		dfs1(x, 0); if (cnt[x] <= k) return true;
		for (int y = x + 1; y <= n; y++) if (cnt[y] && cnt[y] <= k) {
			tot = cnt[y]; dfs3(x, 0, y); if (tot <= k) return true;
		}
	}
	return false;
}
void solve() {
	scanf("%d%d", &n, &k); cur = 0;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
	for (int i = 1; i <= n; i++) dis[i][0] = -1, dfs2(i, 0, i);
	int l = 0, r = n; while (l < r) {int mid = (l + r) >> 1; check(mid) ? r = mid : l = mid + 1;}
	printf("%d\n", r);
}
int main() {
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	int id, T; scanf("%d%d", &id, &T); while (T--) id == 13 || id == 14 ? taskA::solve() : solve();
	return 0;
}