#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int input() {
	int x;
	cin >> x;
	return x;
}
int a[500005];
int f(int u, int t) {
	int ans = 0;
	for (int i = u; i >= 1; i --) {
		if (t >= a[u] - a[i]) t -= (a[u] - a[i]), ans ++;
        else break; 
	}
	return ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = input(), m = input(), ans = -1;
    for (int i = 1; i <= n; i ++) a[i] = input();
    sort(a + 1, a + n + 1);
    for (int i = n; i >= ans; i --) ans = max(ans, f(i, m));
    cout << ans;
	return 0;
}

