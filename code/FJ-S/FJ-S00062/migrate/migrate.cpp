#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 2e6 + 5;

int c, n;
ll d, x[N], dis, num;

void dfs(int now, int des, int tot) {
	if(now == des) {
		if(dis > tot) dis = tot, num = 1;
		else if(dis == tot) num++;
		return;
	}
	for(int i = now + 1; i <= des; i++) {
		if(x[i] - x[now] <= d) {
			dfs(i, des, tot + 1);
		}
	}
}

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(c <= 2) { // O(n^4)
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				dis = 0x3f3f3f3f, num = 0;
				dfs(i, j, 0);
				if(num == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	} else if(11 <= c && c <= 12) { // ÐÔÖÊA
		ll ans = 0, D = x[2] - x[1];
		if(d < D) {
			cout << 0 << endl;
			return;
		}
		for(int i = 1; i <= n; i++) {
			ans += (n - i + 1) / (2 * (d / D));
		}
		cout << ans << endl;
	} else {
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				dis = 0x3f3f3f3f, num = 0;
				dfs(i, j, 0);
				if(num == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
//rp++
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> c >> T;
	while(T--) solve();

	return 0;
}

