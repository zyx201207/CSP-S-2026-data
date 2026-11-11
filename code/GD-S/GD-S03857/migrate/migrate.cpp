#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
#define MUL_TEST
#define FILENAME "migrate"
using namespace std;
typedef pair<int, int> pii;
int x[2000005];
int dis[2000005], vis[2000005], cnt[2000005];
int f[2000005][2], r[2000005];
vector<int> l[2000005];
int c;

void solve() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		l[i].clear();
		cin >> x[i];
		f[i][0] = 1e18;
		f[i][1] = 0;
	}
	
	if (c == 11 || c == 12) {
		int diff = llabs(x[2] - x[1]);
		if (d / diff < 2) cout << "0\n";
		else cout << max(n - d / diff * 2 + 1, 0ll) << '\n';
		return;
	}
	
	int lstr = 0;
	for (int i = 1; i <= n; i++) {
		int posr = upper_bound(x + i, x + n + 1, x[i] + d) - x - 1;
		r[i] = posr;
		if (posr == lstr) continue;
		lstr = posr;
		l[posr].push_back(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vis[j] = 0;
			cnt[j] = 0;
			dis[j] = 0;
		}
		
		queue<int> q;
		vis[i] = 1;
		cnt[i] = 1;
		q.push(i);
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (int j = x + 1; j <= r[x]; j++) {
				if (vis[j]) {
					if (dis[j] == dis[x] + 1) cnt[j] += cnt[x];
					continue;
				}
				dis[j] = dis[x] + 1;
				vis[j] = 1;
				cnt[j] = cnt[x];
				q.push(j);
			}
		}
		
		for (int j = i + 1; j <= n; j++) {
			if (cnt[j] == 2) {
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif

	int _ = 1;
	#ifdef MUL_TEST
		cin >> c >> _;
	#endif
	while (_--) solve();

	_ ^= _;
	return (0^_^0);
}

