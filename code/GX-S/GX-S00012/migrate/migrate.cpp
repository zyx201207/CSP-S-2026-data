#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define pre(i, n, a) for (int i = (n); i >= (a); i--)
#define pb push_back
#define eb emplace_back
#define mp std::make_pair
#define SZ(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
std::mt19937 mrand(std::random_device{}());
int rnd(int x) { return mrand() % x; }
// head

void solve() {
	int n;
	ll d;
	scanf("%d%lld", &n, &d);

	std::vector<ll> x(n + 1);
	rep(i, 1, n) scanf("%lld", &x[i]);

	std::vector<VI> adj(n + 1);
	int r = 1;
	rep(i, 1, n) {
		rep(j, i + 1, n) {
			if (x[j] - x[i] > d) break;
			adj[i].pb(j);
		}
	}

	int ans = 0;
	VI dist(n + 1, 1 << 30), cnt(n + 1);
	rep(i, 1, n) {
		std::queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y : adj[x]) if (dist[y] > dist[x] + 1) {
				cnt[y] = 1;
				dist[y] = dist[x] + 1;
				q.push(y);
			} else if (dist[y] == dist[x] + 1) {
				++cnt[y];
				q.push(y);
			}
		}
		rep(j, i + 1, n) ans += cnt[j] == 2;
		rep(j, 1, n) dist[j] = 1 << 30, cnt[j] = 0;
	}

	printf("%d\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int tc, T;
	scanf("%d%d", &tc, &T);

	for (; T--; ) solve();

	return 0;
}