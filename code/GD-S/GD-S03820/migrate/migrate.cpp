#include<bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 2e6 + 10;
ll c, d, n, t, x[N], mn[N], ans, vis[N];
vector<ll> g[N];
queue<PII> q;

void bfs(ll s) {
	q.push({s, 0});
	while(!q.empty()) {
		auto f = q.front();
		q.pop();
		for(auto v:g[f.first]) {
			if((c == 13 || c == 14) && (f.second + 1 >= 3)) continue;
			if(f.second + 1 < mn[v]) {
				mn[v] = f.second + 1;
				vis[v] = 1;
				q.push({v, f.second + 1});
			} else if (f.second + 1 == mn[v]) {
				++vis[v];
				q.push({v, f.second + 1});
			}
		}
	}
}

inline void init() {
	FOR(i, 1, n) g[i].clear();
    ans = 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		FOR(i, 1, n) cin >> x[i];
		FOR(i, 1, n)
			FOR(j, i + 1, n)
				if(x[j] - x[i] <= d) g[i].emplace_back(j), g[j].emplace_back(i);
				else break;
		FOR(i, 1, n) {
			FOR(j, 1, n) mn[j] = LLONG_MAX;
			mn[i] = 0;
			bfs(i);
			FOR(j, i + 1, n) {
				if(vis[j] == 2) ++ans;
				vis[j] = 0;
			}
		}
		cout << ans << '\n';
		init();
	}
	return 0;
}
/*
What's up
It seems that T3 is easier.
100 + 0 + 40 = 140pts
It is more than last 2 years
Seems NOIP Possible
*/
