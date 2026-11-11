#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= (int)y; i++)
#define foR(i, x, y) for (int i = x; i >= (int)y; i--)
#define fin(x) freopen(x, "r", stdin);
#define fou(x) freopen(x, "w", stdout);
#define fre(x) fin(x".in") fou(x".out")
#define ios cin.tie(0) -> sync_with_stdio(false);
#define itn int
#define tin int
#define tni int
#define nit int
#define nti int
#define imnt int
#define inmt int
using ll = long long;
using lll = __int128_t;
using namespace std;
int main() {
	fre("migrate")
	ios
	int c, t;
	cin >> c >> t;
	(void)c;
	while (t--) {
		ll n, d, ans = 0;
		cin >> n >> d;
		vector<ll>y(n + 1);
		For(i, 1, n) cin >> y[i];
		For(i, 1, n) {
			queue<pair<ll, ll>>q;
			q.push({i, 0});
			vector<pair<ll, ll>>cnt(n + 1, {1e18, 0});
			while (!q.empty()) {
				ll x = q.front().first, stp = q.front().second;
				q.pop();
				if (stp < cnt[x].first) cnt[x] = {stp, 1};
				else if (stp == cnt[x].first) cnt[x].second++;
				else continue;
				For(j, x + 1, n) {
					if (y[j] - y[x] <= d) q.push({j, stp + 1});
					else break;
				}
			}
			For(j, i + 1, n) if (cnt[j].second == 2) ans++;
		}
		cout << ans << '\n';
	}
}
