#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q;
void solve() {
    ll sum = 0;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
