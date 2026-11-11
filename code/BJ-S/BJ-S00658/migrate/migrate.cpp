#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e6 + 10;

LL x[N];
LL dist[N];
LL cnt[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	if (c <= 10 || c >= 13) {
		while (T -- ) {
			int n; LL d;
			cin >> n >> d;
			for (int i = 1; i <= n; i ++ ) cin >> x[i];
			LL ans = 0;
			for (int i = 1; i <= n; i ++ ) {
				memset(dist, 0x3f, (n + 10) * 8);
				memset(cnt, 0, (n + 10) * 8);
				dist[i] = 0;
				cnt[i] = 1;
				for (int u = i; u <= n; u ++ ) {
					for (int v = u + 1; v <= n; v ++ ) {
						if (x[v] - x[u] > d) break;
						if (dist[u] + 1 < dist[v]) {
							dist[v] = dist[u] + 1;
							cnt[v] = cnt[u];
						} else if (dist[u] + 1 == dist[v]) cnt[v] += cnt[u];
					}
				}
				for (int j = i + 1; j <= n; j ++ ) {
					if (dist[j] < 0x3f3f3f3f3f3f3f3f && cnt[j] == 2) ans ++ ;
				}
			}
			cout << ans << endl;
		}
	} else if (c == 11 || c == 12) {
		while (T -- ) {
			int n; LL d;
			cin >> n >> d;
			for (int i = 1; i <= n; i ++ ) cin >> x[i];
			if (2 * (x[2] - x[1]) <= d) 
				cout << max(0ll, n - d / (x[2] - x[1]) * 2 + 1) << endl;
			else cout << 0 << endl;
		}
	}
}
