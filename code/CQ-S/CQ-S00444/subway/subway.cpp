#include <bits/stdc++.h>
#define re read()
#define wr(x) write(x)
#define sp putchar(' ')
#define endl puts("")
#define int long long

const int N = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

int read() {
	int y = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f = c == '-' ? -1 : f, c = getchar();
	while (c >= '0' && c <= '9') y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return y * f;
}

void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

using pii = pair<int, int>; 

int n, m, d, q;
int w[N];
int dis[510][510];
vector<pii> id[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int XXXXXXXXXXXX = re;
	n = re, m = re, d = re, q = re;
	for (int i = 1; i <= m; i++) w[i] = re;
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++) {
		int k = re;
		for (int j = 1; j <= k; j++) {
			int u = re, t = re;
			for (auto X : id[u]) dis[X.first][i] = dis[i][X.first] = min(dis[X.first][i], t + X.second);
			id[u].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++) for (int k = 1; k <= n; k++) for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	while (q--) {
		int s = re, t = re, ans = INF;
		for (auto X : id[s]) for (auto Y : id[t]) ans = min(ans, w[s] + w[t] + dis[X.first][Y.first] + X.second + Y.second);
		wr(ans), endl;
	} 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

