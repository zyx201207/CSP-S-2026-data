#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

const int N = 2e6 + 5;
int c, t;
int n, d;
int x[N];
int nxt[N], pre[N];
int dist[N];
int sum[N];
bool inq[N];

inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++) {
		int l = i, r = n;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if (x[m] - x[i] <= d) l = m;
			else r = m - 1;
		}
		nxt[i] = l;
		l = 1, r = i;
		while(l < r) {
			int m = (l + r) / 2;
			if (x[i] - x[m] <= d) r = m;
			else l = m + 1;
		}
		pre[i] = l;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			dist[j] = 1e9;
		dist[i] = 0;
		for (int j = i + 1; j <= n; j++) {
			for (int k = pre[j]; k <= j - 1; k++) {
				dist[j] = min(dist[j], dist[k] + 1);
			}
		}
		for (int j = i + 1; j <= n; j++)
			sum[j] = 0;
		sum[i] = 1;
		queue<int> q;
		q.push(i);
		inq[i] = true;
		while(!q.empty()) {
			int it = q.front();
			q.pop();
			inq[it] = false;
			for (int i = it + 1; i <= nxt[it]; i++) {
				if (dist[it] + 1 > dist[i]) continue;
				sum[i] += sum[it];
				if (!inq[i]) {
					q.push(i);
					inq[i] = true;
				}
			}
		}
		for (int j = i + 1; j <= n; j++) {
			if (sum[j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--) solve();
}
