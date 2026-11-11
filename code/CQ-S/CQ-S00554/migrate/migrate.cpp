#include <bits/stdc++.h>

using namespace std;
const int N = 2e6;
long long t, n, a[N + 5], d;
long long cnt_l[N + 5], cnt_r[N + 5];
long long ga_l[N + 5], ga_r[N + 5];
long long lim_l[N + 5], lim_r[N + 5];
long long ans;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t >> t;
	while(t --) {
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
			ga_l[i] = ga_r[i] = 0;
			cnt_l[i] = cnt_r[i] = 0;
		}
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		int pl = 1;
		for(int i = 1; i <= n; i ++) {
			while(a[i] - a[pl] > d) pl ++;
			if(pl == i) lim_l[i] = -1;
			else lim_l[i] = pl;
		}
		pl = n;
		for(int i = n; i; i --) {
			while(a[pl] - a[i] > d) pl --;
			if(pl == i) lim_r[i] = -1;
			else lim_r[i] = pl;
		}
		for(int i = 1; i <= n; i ++) {
			if(lim_r[i] != -1) {
				cnt_l[lim_r[i]] ++;
				if(lim_l[lim_r[i]] == i) {
					cnt_l[lim_r[i]] += cnt_l[i];
				}
				if(lim_r[i] != i + 1) {
					ga_l[lim_r[i]] ++;
					if(lim_l[lim_r[i] - 1] == i) {
						ga_l[lim_r[i]] += cnt_l[i];
					}
				}
			}
		}
		for(int i = n; i; i --) {
			if(lim_l[i] != -1) {
				cnt_r[lim_l[i]] ++;
				if(lim_r[lim_l[i]] == i) {
					cnt_r[lim_l[i]] += cnt_r[i];
				}
				if(lim_l[i] != i - 1) {
					ga_r[lim_l[i]] ++;
					if(lim_r[lim_l[i] + 1] == i) {
						ga_r[lim_l[i]] += cnt_r[i];
					}
				}
			}
		}
		ans = 0;
		for(int i = 1; i < n; i ++) {
			ans += ga_r[i] * ga_l[i + 1];
		}
		cout << ans << '\n';
	}
	return 0;
}

