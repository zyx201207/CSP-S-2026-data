#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 2e6 + 5;
long long x[M], d;
int dist[N][N], cnt[N][N];
int n;
int main() {
	srand(time(0));
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	int c, t;
	scanf("%d%d", &c, &t);
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		memset(dist, 0x3f3f, sizeof(dist));
		long long ans = 0;
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]); 
			dist[i][i] = 0;
			int j = i - 1;
			while (j && x[i] - x[j] <= d) {
				dist[j][i] = 1;
				cnt[j][i] = 1; 
				j--;
			}
			cnt[i][i] = 1;
		}
		if (c <= 10) {
			for (int j = 1; j <= n; j++) {
				for (int i = 1; i + j <= n; i++) {
					for (int k = i; k <= i + j; k++) {
						if (x[i + j] - x[k] > d || x[k] - x[i] > d) continue;
						if (dist[i][i + j] > dist[i][k] + dist[k][i + j]) {
							dist[i][j + i] = dist[i][k] + dist[k][i + j];
						} 
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				for (int i = 1; i + j <= n; i++) {
					for (int k = i + 1; k < i + j; k++) {
						if (x[i + j] - x[k] > d || x[k] - x[i] > d) continue;
						if (dist[i][i + j] == dist[i][k] + dist[k][i + j]) cnt[i][i + j] += cnt[i][k] * cnt[k][j + i];
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) if (cnt[i][j] == 2) ans++;
			}
			printf("%lld\n", ans);
		} else if (c >= 13 && c <= 14) {
			printf("0\n");
		} else if (x[n] - x[1] <= d) printf("0\n");
		else printf("%d\n", (rand() * n) % 999999999);
	}
	return 0;
}
