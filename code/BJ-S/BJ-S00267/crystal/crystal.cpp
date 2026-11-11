#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, a[N], maxn, minn, b[N];
bool chk(int x) {
    ll sum = 0;
    for (int i = 1; i <= x; i++) 
        sum += (b[x] - b[i]);
    return sum <= m;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    ll l = 0, r = n, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (chk(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}