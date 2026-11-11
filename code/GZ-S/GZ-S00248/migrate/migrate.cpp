//孙宇宸 GZ-S00248 贵阳市华师一学校 
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using lll = __int128_t;

constexpr ll P = (1ll << 61) - 1;

void solve() {
	int n;
	ll d;
	cin >> n >> d;
	vector<ll> x(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	auto redu = [](ll x) {
		return x >= P ? x - P : x;
	};
	ll ans = 0;
	for (int s = 1; s <= n; ++s) {
		vector<int> f(n + 1, 1 << 30);
		vector<ll> g(n + 1, 0);
		f[s] = 0;
		g[s] = 1;
		deque<int> dq;
		dq.push_back(s);
		vector<deque<int>> vec(n + 1);
		vector<lll> sm(n + 1);
		vec[0].push_back(s);
		sm[0] = 1;
		for (int i = s + 1; i <= n; ++i) {
			int p = lower_bound(x.begin() + 1, x.begin() + n + 1, x[i] - d) - x.begin();
			while (!dq.empty() && dq.front() < p) {
				dq.pop_front();
			}
			if (!dq.empty()) {
				f[i] = f[dq.front()] + 1;
				while (!dq.empty() && f[dq.back()] >= f[i]) {
					dq.pop_back();
				}
				dq.push_back(i);
				while (!vec[f[i] - 1].empty() && vec[f[i] - 1].front() < p) {
					sm[f[i] - 1] -= g[vec[f[i] - 1].front()];
					vec[f[i] - 1].pop_front();
				}
				ans += (g[i] = sm[f[i] - 1] % P) == 2;
				vec[f[i]].push_back(i);
				sm[f[i]] += g[i];
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	} 
	return 0;
}
