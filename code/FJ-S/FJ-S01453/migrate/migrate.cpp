#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, ans;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		vector<int> x(n + 1);
		for(int i = 1; i <= n; ++ i) cin >> x[i];
		if(n <= 3) {
			cout << "0\n";
			continue;
		}
		if(c == 11 || c == 12) {
			int cha = x[2] - x[1];
			int tmp = d / cha;
			if(tmp <= 1) {
				cout << "0\n"
				continue;
			}
			cout << n - tmp - 1 << '\n';
			continue;
		}
		
		for(int i = 1; i < n; ++ i)
			for(int j = i + 1; j <= n; ++ j) {
				vector<int> dis(n + 1, 0x3f3f3f3f3f3f3f3f), cnt(n + 1);
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				pq.emplace(0, i);
				dis[i] = 0; cnt[i] = 1;
				while(pq.size()) {
					int u = pq.top().second;
					pq.pop();
					for(int k = u + 1; k <= j; ++ k) {
						if(x[k] - x[u] > d) break;
						if(dis[u] + 1 < dis[k])
							dis[k] = dis[u] + 1, cnt[k] = cnt[u], pq.emplace(dis[k], k);
						else if(dis[u] + 1 == dis[k])
							cnt[k] += cnt[u];
					}
					
				}
				if(cnt[j] == 2) ++ ans;
			}
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
