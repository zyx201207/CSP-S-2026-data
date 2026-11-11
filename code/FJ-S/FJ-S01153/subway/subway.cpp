#include <iostream>
#include <cstring>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define M 500005
#define N 505
#define D 25
#define pii pair<int, int>
#define fi first
#define se second
#define mkpr make_pair
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f

int c, n, m, d, q;
int w[M], k[N], dp[N][N];
int a[M][D][2];

signed main() {
	Write by ___NightDay___;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			int v, w;
			cin >> v >> w;
			a[v][0][0] ++;
			a[v][a[v][0][0]][0] = i;
			a[v][a[v][0][0]][1] = w;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= a[i][0][0]; j ++) {
			for (int l = j + 1; l <= a[i][0][0]; l ++) {
				dp[a[i][j][0]][a[i][l][0]] = min(dp[a[i][j][0]][a[i][l][0]], a[i][j][1] + a[i][l][1]);
				dp[a[i][l][0]][a[i][j][0]] = min(dp[a[i][l][0]][a[i][j][0]], a[i][l][1] + a[i][j][1]);
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		dp[i][i] = 0;
	}
	for (int l = 1; l <= n; l ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
			}
		}
	}
	while (q --) {
		int u, v;
		cin >> u >> v;
		int ans = inf;
		for (int i = 1; i <= a[u][0][0]; i ++) {
			for (int j = 1; j <= a[v][0][0]; j ++) {
				if (dp[a[u][i][0]][a[v][j][0]] + w[u] + w[v] + a[u][i][1] + a[v][j][1] < ans) {
					ans = dp[a[u][i][0]][a[v][j][0]] + w[u] + w[v] + a[u][i][1] + a[v][j][1];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

// O(md^2+nm+n^3) = 575,000,000
// CCF 神机保佑[祈祷]
// 上午的 36pts 和去年的 35pts 现在还给我行不行啊[祈祷][祈祷][祈祷]
// I did it!!!!!!!!!!!!!
// 80~100pts
