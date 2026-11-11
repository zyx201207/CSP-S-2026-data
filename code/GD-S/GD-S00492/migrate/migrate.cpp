#include <bits/stdc++.h>
namespace GD00492 {
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int maxn(2e6 + 9);
int n, R[maxn], L[maxn];
ll d, x[maxn];
ll ans;
int dis[5005][5005];
void init() {
	ans = 0;
}
void mian() {
	init();
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	for (int i = 1, j = 1; i <= n; ++i) { // [i,j)
		j = max(i + 1, j);
		while (j <= n && x[j] - x[i] <= d) ++j;
		R[i] = j - 1;
	}
	for (int i = n, j = n; i >= 1; --i) { // (j,i]
		j = min(i - 1, j);
		while (j >= 1 && x[i] - x[j] <= d) --j;
		L[i] = j + 1;
	}
	for (int i = 1; i <= n; ++i) {
		memset(dis[i] + 1, 0x3f, sizeof(dis[0][0]) * n);
		dis[i][i] = 0;
		static int li[maxn], fr, ba;
		li[fr = ba = 1] = i;
		for (int j = i + 1; j <= n; ++j) {
			while (fr <= ba && x[j] - x[li[fr]] > d) ++fr;
			if (fr > ba) continue;
			dis[i][j] = dis[i][li[fr]] + 1;
			while (fr <= ba && dis[i][li[ba]] > dis[i][j]) --ba;
			li[++ba] = j;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = R[i] + 1; j <= n; ++j) if (1 + dis[R[i]][j] == dis[i][j] && 1 + dis[i][L[j]] == dis[i][j]) {
			int cnt = 0;
			for (int k = i + 1; k < j; ++k) {
				cnt += dis[i][k] + dis[k][j] == dis[i][j];
				if (cnt > dis[i][j]) break;
			}
			if (cnt == dis[i][j])
				++ans;
		} else break;
	}
	cout << ans << '\n';
}
} using namespace GD00492;
int main() {
#ifdef LOCAL00492
	freopen("migrate6.in", "r", stdin),
	freopen("my.out", "w", stdout);
#else
	freopen("migrate.in", "r", stdin),
	freopen("migrate.out", "w", stdout);
#endif
	ios::sync_with_stdio(false),
	cin.tie(nullptr), cout.tie(nullptr);
	int c, T = 1;
	cin >> c >> T;
	while (T--) mian();
	return 0;
}

