#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1e9 + 7;

struct Nd {
	int u, w;
};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		vector<long long> x(n);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			vector<int> dis(i + 1, INF), cnt(i + 1);
			queue<Nd> q;
			q.push({i, 0});
			dis[i] = 0;
			cnt[i] = 0;
			while (!q.empty()) {
				const Nd cu = q.front();
				q.pop();
				if (dis[cu.u] < cu.w) continue;
				cnt[cu.u]++;
				dis[cu.u] = cu.w;
				for (int j = cu.u - 1; j >= 0 && x[cu.u] - x[j] <= d; j--) {
					if (dis[j] < cu.w + 1) continue;
					q.push({j, cu.w + 1});
				}
			}
			for (int j = 0; j < i; j++) {
				if (cnt[j] == 2) ans++;
			}
		}
		
		cout << ans << '\n';
	}
	cout << endl;
} 
