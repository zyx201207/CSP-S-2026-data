#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int c, t, n;
long long d, x[2000005], dis[5005][5005];
const long long inf = 1ll << 61;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = inf;
		for (int i = 1; i <= n; i++)
			dis[i][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (abs(x[i] - x[j]) <= d)
					dis[i][j] = 1;
		long long ans = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long cnt = 0;
				for (int k = 1; k <= n; k++)
					if (dis[i][j] != inf && dis[i][k] + dis[k][j] == dis[i][j])
						cnt++;
				if (cnt == 2)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
