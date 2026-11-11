#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 5005;
ll c, n, d, a[maxn], dis[maxn], cnt[maxn], be[maxn], q[maxn], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T;
	cin >> c >> T;
	while(T --) {
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j <= n; j ++) {
				q[j] = cnt[j] = dis[j] = be[j] = 0;
			}
			ll h = 1, t = 0;
			q[++ t] = i;
			cnt[0] = 1;
			for(int j = i + 1; j <= n; j ++) {
				while(h <= t && a[q[h]] + d < a[j]) {
					cnt[dis[q[h]]] -= be[q[h]];
					h ++;
				}
				if(h > t)
					break;
				ll mnc = cnt[dis[q[h]]];
				if(mnc == 2)
					ans ++;
					
				dis[j] = dis[q[h]] + 1;
				be[j] = cnt[dis[q[h]]];
				cnt[dis[j]] += cnt[dis[q[h]]];
				while(h <= t && dis[q[t]] > dis[j]) {
					cnt[dis[q[t]]] -= be[q[h]];
					t --;
				}
				q[++ t] = j;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
