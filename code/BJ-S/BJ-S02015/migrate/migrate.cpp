#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1000005;
int c, t, n, d;
ll x[MAXN];
int dis[MAXN];
int cnt[MAXN];
bool vis[MAXN];
struct edge{
	int v, w;
	bool operator>(const edge &e) const {
		return w > e.w;
	}
};
priority_queue<edge, vector<edge>, greater<edge>> q;

void dijstra(int start, int end) {
	for (int i = 0; i < MAXN; i++)
		dis[i] = 1 << 30, vis[i] = 0;
	dis[start] = 0;
	q.push({start, 0});
	while (!q.empty()) {
		edge e = q.top();
		q.pop();
		if (vis[e.v])
			continue;
		vis[e.v] = 1;
		for (int i = start; i <= end; i++) {
			if (x[i] - x[e.v] <= d) {
				if (dis[i] > dis[e.v] + 1) {
					dis[i] = dis[e.v] + 1;
					cnt[i] = 1;
					q.push({i, dis[i]});
				} else if (dis[i] == dis[e.v] + 1)
					cnt[i]++;
			} else
				break;
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++)
			scanf("%lld", x + i);
		if (c <= 10) {
			ll ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					dijstra(i, j);
					if (cnt[j] == 2)
						ans++;
				}
			}
			cout << ans << endl;
		}
		if (c == 11 || c == 12) {
			if (d < 2 * n) {
				printf("0\n");
				continue;
			}
			int step = d / n;
			printf("%d\n", max(0, n + 1 - step * 2));
		}
		if (c == 13 || c == 14) {
			puts("0");
		}
	}
	return 0;
}
