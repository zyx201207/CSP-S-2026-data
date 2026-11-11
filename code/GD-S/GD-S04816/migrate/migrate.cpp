#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 405;
int c, t, n, d, a[N], mx[N];
int in[N], dis[N], cnt[N];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int l = i, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (a[mid] <= a[i] + d) {
					l = mid + 1;
					mx[i] = mid;
				} else {
					r = mid - 1;
				}
			}
		}
		int ans = 0;
		for (int st = 1; st <= n; st++) {
			memset(dis, 63, sizeof(dis));
			memset(cnt, 0, sizeof(cnt));
			dis[st] = 0;
			for (int i = 1; i <= n; i++) 
				for (int j = i + 1; j <= mx[i]; j++) 
					in[j]++;
			queue<int> q;
			for (int i = 1; i <= n; i++)
				if (!in[i]) q.push(i);
			while (!q.empty()) {
				int cur = q.front(); 
				q.pop();
				for (int i = cur + 1; i <= mx[cur]; i++) {
					--in[i];
					if (dis[i] > dis[cur] + 1) {
						dis[i] = dis[cur] + 1;
						cnt[i] = 1;
					} else if (dis[i] == dis[cur] + 1) {
						cnt[i]++;
					}
					if (!in[i]) q.push(i);
				}
			}
			for (int i = 1; i <= n; i++)
				if (cnt[i] == 2) ans++;
		}
		cout << ans << endl;
	}
 	return 0;
}

