#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5;
ll n, k, a[N];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n, greater<ll>());
    ll maxn = a[1];
    for (int i = 2; i <= k; i++) {
        maxn = (maxn & a[i]);
    }
    cout << maxn;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
