// GZ-S00091 »Æ¼ÑÂå »ªÊ¦Ò»¹óÑô 
#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define iv inline void
#define it inline int
#define pb push_back
#define LL long long
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 2e6 + 10, M = 5010;

int n;
LL w[N], d;
vector<int> g[N];
int dist[N], cnt[N];
map<PII, bool> st, mp;
int ans = 0;

void dij(int s) {
	priority_queue<PII, vector<PII>, greater<PII>> q;
	upp(i, 1, n) dist[i] = -1, cnt[i] = 0;
	dist[s] = 0, cnt[s] = 1;
	q.push({0, s});
	while (!q.empty()) {
		PII t = q.top(); q.pop();
		if (t.x > dist[t.y]) continue;
//		if (s == 1) cout << t.x << ' ' << t.y << ' ' << cnt[t.y] << endl;
		for (int j : g[t.y]) {
//			if (j == 5 && s == 1) cout << dist[j] << ' ' << t.y << ' ' << dist[t.y] << ' ' << cnt[j] << ' ' << cnt[t.y] << endl;
			if (dist[j] == -1 || dist[j] > dist[t.y] + 1) {
				dist[j] = dist[t.y] + 1;
				cnt[j] = cnt[t.y];
				q.push({dist[j], j});
			}
			else if (dist[j] == dist[t.y] + 1) {
				cnt[j] = cnt[t.y] + cnt[j];
			}
		}
	}
	upp(i, 1, n) if (cnt[i] == 2 && i != s && !st[{s, i}]) {
		ans++, st[{s, i}] = st[{i, s}] = 1;
//		cout << cnt[i] << endl;
	}
}

iv solve() {
	st.clear(), mp.clear();
	ans = 0;
	cin >> n >> d;
	upp(i, 1, n) cin >> w[i];
	int j = 1, k = 0;
	upp(i, 1, n) {
		upp(j, 1, n) if (abs(w[i] - w[j]) <= d && i != j) g[i].pb(j);
	}
	upp(i, 1, n) dij(i);
	upp(i, 1, n) g[i].clear();
	cout << ans << endl;
}

signed main() {
	 freopen("migrate.in", "r", stdin);
	 freopen("migrate.out", "w", stdout);	
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int c, T; cin >> c >> T;
	while (T--) solve();
	return 0;
}
