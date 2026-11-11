#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;

const int M = 5e5, N = 500, D = 20;
int C, n, m, d, q;
int w[M+5];
LL dis[N+5][N+5];
int cnt[M+5], a[M+5][D];
LL t[M+5][D];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, len; i <= n; i++) {
		cin >> len;
		for (int u; len--; cnt[u]++) {
			cin >> u;
			a[u][cnt[u]] = i;
			cin >> t[u][cnt[u]];
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			for (int k = 0; k < cnt[i]; k++)
				dis[a[i][j]][a[i][k]] = min(dis[a[i][j]][a[i][k]], t[i][j] + t[i][k]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	for (int u, v; q--;) {
		LL res = 4e18;
		cin >> u >> v;
		for (int i = 0; i < cnt[u]; i++) {
			for (int j = 0; j < cnt[v]; j++) res = min(res, dis[a[u][i]][a[v][j]] + t[u][i] + t[v][j]);
		}
		cout << res + w[u] + w[v] << '\n';
	}
	return 0;
}
/*
我没在强校训练，纯跟 AI 学。
我本来想跑 n 轮 Dij，有趣的是 GPT 老师狠狠批评了我。 
*/
/*
我觉的这个题很像要把它抽线成点来做。
地铁线路抽象成点，然后站向线连边。
然后找地铁线路到另一个地铁线路间的距离，floyd。
d<=20 很有启发性，枚举每个站所能到达的线。
但一秒 2.5e8 冲的过去吗？[84,92] 比去年能看。
双向任意通行，那没事了脑补了。
我是如何虚空调试 25min 的。
现在上迷惑行为大赏就像过初赛，但我整个初中都没有过。
*/
