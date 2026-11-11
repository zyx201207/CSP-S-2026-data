#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 5e5 + 5;
int n, m, a[maxn], ans = 0, d[maxn], sd[maxn], msd[maxn];

int check(int ind, int num) {
	return (m >= ((msd[ind - 1] - msd[ind - 1 - num]) - (ind - num - 1) * (sd[ind - 1] - sd[ind - 1 - num])));
}

signed main() {
    (void)freopen("crystal.in", "r", stdin);
    (void)freopen("crystal.out", "w", stdout);
    (void)scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++) (void)scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 2; i <= n; i++) d[i - 1] = a[i] - a[i - 1];
    for(int i = 1; i < n; i++) sd[i] = sd[i - 1] + d[i];
    for(int i = 1; i < n; i++) msd[i] = msd[i - 1] + d[i] * i;
    for(int i = 1; i <= n; i++) {
		int l = 1, r = i, res = 0;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(check(i, mid)) {
				res = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		ans = max(ans, res + 1);
    }
    (void)printf("%lld", ans);
    return 0;
}

