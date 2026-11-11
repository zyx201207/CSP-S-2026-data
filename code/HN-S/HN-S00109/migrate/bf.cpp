#include <bits/stdc++.h>
using namespace std;

#define ll long long 


//#define cout fout
//#define cin fin
//ifstream fin("migrate.in");
//ofstream fout("migrate.ans");

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int c, t;

void solve() {
	ll n, d;
	cin >> n >> d;
//	assert(n <= 1e4);
	vector <ll> vx(n + 1);
	vector <vector <int> > ve(n + 1);
	for (int i = 1; i <= n; i++) cin >> vx[i];
	int r = 1;
	for (int i = 1; i <= n; i++) {
		while (r + 1 <= n && vx[r + 1] - vx[i] <= d) r++;
		for (int j = i + 1; j <= r; j++) {
			ve[i].push_back(j);
//			cout << i << ' ' << j << '\n';
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		vector <ll> dis(n + 1, inf), cnt(n + 1);
		queue<int> q;
		q.push(i);
		dis[i] = 0;
		cnt[i] = 1;
		while (q.size()) {
			auto now = q.front(); q.pop();
			for (auto nxt : ve[now]) {
				if (dis[now] + 1 <= dis[nxt]) {
					if (dis[now] + 1 < dis[nxt]) {
						q.push(nxt);
					}
					cnt[nxt] += cnt[now];
					if (cnt[nxt] >= inf) cnt[nxt] = inf;
					dis[nxt] = dis[now] + 1;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (cnt[j] == 2) {
				cout << i << ' ' << j << ' ' << dis[j] << '\n';
			}
		}
		for (auto j : cnt) {
			ans += j == 2;
		}
	}
	cout << ans << '\n';
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	
} 


/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
