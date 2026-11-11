// B subway: 1s 1,024MiB. GREEN-CYAN.

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int maxn = 505, maxm = 5e5+5;

long long f[maxn][maxn];
long long W[maxm], T[maxm][25];
long long GXR[maxm], A[maxm][25];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int C, n, m, d, q;
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> W[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		while (k--) {
			int x; cin >> x;
			GXR[x]++;
			A[x][GXR[x]] = i;
			cin >> T[x][GXR[x]]; 
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int t = 1; t <= m; t++) {
		for (int i = 1; i <= GXR[t]; i++)
			for (int j = i + 1; j <= GXR[t]; j++) {
				int u = A[t][i], v = A[t][j];
				f[u][v] = f[v][u] = min(f[u][v], T[t][i] + T[t][j]);
			}
	}
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int i = 1; i <= GXR[x]; i++)
			for (int j = 1; j <= GXR[y]; j++) {
				int u = A[x][i], v = A[y][j];
				ans = min(ans, T[x][i] + f[u][v] + T[y][j]);
			}
		cout << ans + W[x] + W[y] << endl;
	}
	return 0;
}
