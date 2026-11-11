#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, m;
ll a[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());
    if (m == 1) {
        cout << a[1] << "\n";
        return ;
    }
    int ans = a[1];
    int cnt = 0;
    bool flag = 0;
    for (int i = 2; i <= m + cnt; i++) {
        if (m + cnt > n) {
            flag = 1;
            break;
        }
        if ((ans & a[i]) == 0) {
            cnt++;
            ans = a[i];
        }
        else ans = (ans & a[i]);
    }
    if (flag == 1) {
            ans = a[1];
        for (int i = 2; i <= m; i++) {
            ans = (ans & a[i]);
        }
    }
    cout << ans << "\n";
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
