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

char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
inline ll read() {char op = getchar(); ll x = 0, f = 1; while (op < 48 || op > 57) {if (op == '-') f = -1; op = getchar();} while (48 <= op && op <= 57) x = (x << 1) + (x << 3) + (op ^ 48), op = getchar(); return x * f;}

const int N = 2e6 + 5;
ll x[N], d; int n, cid, las[N], nex[N], dis[5005][5005];
ll solve(int L, int R) {
	for (int i = L, j = L; i <= n; i++) {while (j < i && x[i] - x[j] > d) j++; las[i] = j;}
	for (int i = R, j = R; i; i--) {while (j > i && x[j] - x[i] > d) j--; nex[i] = j;}
	ll ans = 0;
	for (int i = L; i <= R; i++) for (int j = i + 1; j <= R; j++) dis[i][j] = dis[j][i] = dis[i][max(las[j], i)] + 1;
	for (int i = L; i <= R; i++) for (int j = i + 1; j <= R; j++) {
		int c = 0; for (int x = i + 1; x < j; x++) c += (dis[i][x] + dis[x][j] == dis[i][j]);
		ans += (c == dis[i][j]);
	}
	return ans;
}
void solve() {
	ll ans = 0; n = read(), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	if (cid == 11 || cid == 12) {
		if (n == 1 || x[2] - x[1] > d) puts("0");
		else if (d == (x[2] - x[1])) printf("%d\n", 0);
		else if (d < x[3] - x[1]) puts("0");
		else printf("%lld\n", max(0ll, n - d / (x[2] - x[1]) * 2 + 1));
		return;
	}
	for (int i = 1, j = 1; i <= n; i++) if (i == n || x[i + 1] - x[i] > d) ans += solve(j, i), j = i + 1;
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	cid = read(); int T = read(); while (T--) solve();
	return 0;
}
//对不起。