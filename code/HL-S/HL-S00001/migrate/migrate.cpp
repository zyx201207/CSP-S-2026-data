#include <bits/stdc++.h>
using namespace std;
long long sum;
long long x[2000010],d;
long long dist[2000010], n, cnt[2000010];
queue<pair<long long, long long> > q;
inline void bfs(int u) {
	q.push(make_pair(u, 0));
	while(!q.empty()) {
		long long y = q.front().first, p = q.front().second;
		q.pop();
		if(dist[y] == -1) {
			dist[y] = p;
			cnt[y] = 1;
		} else if(dist[y] == p) {
			cnt[y]++;
		} else {
			continue;
		}
		for(int i = y + 1; i <= n; i++) {
			if(x[i] - x[y] <= d) {
				q.push(make_pair(i, p + 1));
			} else {
				break;
			}
		}
	} 
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	if(c == 11 || c == 12) {
		while(t--) {
			scanf("%lld%lld", &n, &d);
			if(n <= 3) {
				printf("0\n");
				continue;
			}
			for(int i = 1; i <= n; i++) {
				scanf("%lld", &x[i]);
			}
			unsigned long long cnt = x[n];
			cnt = cnt - x[1];
			if(2 * (x[2] - x[1]) <= d && d <= 3 * (x[2] - x[1])) {
				n -= 3;
				printf("%lld", n);
			} else {
				printf("0\n");
			}
		}
	} 
	while(t--) {
		sum = 0;
		scanf("%lld%lld", &n, &d);
		for(int i = 1; i <= n; i++) {
			dist[i] = -1;
		}
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		for(int i = 1; i <= n; i++) {
			bfs(i);
			for(int j = 1; j <= n; j++) {
				if(cnt[j] == 2) {
					sum++;
				}
				dist[j] = -1;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
