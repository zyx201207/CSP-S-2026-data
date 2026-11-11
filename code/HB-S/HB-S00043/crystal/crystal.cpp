#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const ll N = 5e5 + 10;
ll n, m, a[N], pre[N], ans;
bool check(ll i, ll j) {
    return (a[j] * (j - i + 1) - (pre[j] - pre[i - 1])) <= m;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for(ll i = 1, l, r, mid; i <= n; i++) {
        l = i, r = n;
        while(l <= r) {
            mid = (l + r) / 2;
            if(check(i, mid)) l = mid + 1;
            else r = mid - 1;
        } // res is r
        ans = max(ans, r - i + 1);
    }
    cout << ans << endl;
    return 0;
}