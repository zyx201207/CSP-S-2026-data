#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
ll n, m, ans, maxx = INT_MIN, maxi, a[N], summ[N];
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48ll);
		ch = getchar();
	}
	return x * f;
}
ll calc(ll x, ll y) {
	ll k = (x + y) / 2;
	return max(min(k, n), 1ll);
}
int find(ll l, ll r, ll now, ll x) {
	if (l >= r) return now;
	ll mid = l + r >> 1; 
	if (l < maxi && r > maxi) {
		ll res1 = lower_bound(summ + l, summ + maxi + 1, x) - summ, res2 = find(maxi + 1, r, calc(maxi + 1, r), x);
		return (summ[res1] >= x) ? res1 : res2;
	}
	if (l >= maxi) return find(l, mid, calc(l, mid), x); 
	return lower_bound(summ + l, summ + r + 1, x) - summ;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) summ[i] = summ[i + 1] + a[i];
    for (int i = 1; i <= n; i++) 
    	if (maxx < summ[i]) {
    		maxx = summ[i];
    		maxi = i;
		}
    for (ll i = 1; i <= n; i++) {
        int id = find(1, i, (i + 1) / 2, summ[i + 1] + a[i] * i - m);
        if (summ[id] >= summ[i + 1] + a[i] * i - m) ans = max(ans, i - id + 1ll);
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
}
