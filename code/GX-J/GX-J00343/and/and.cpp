#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ans = 0, n;
vector<ll> a;
void dfs(int m, int i, ll val) {
    if(i + 1 + m > n) return;
    if(m == 0) {
        ans = max(ans, val);
        return;
    }
    for(int j = i + 1;j < n;j++) {
        dfs(m - 1, j, val & a[j]);
        dfs(m, j, val);
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> n >> m;
    a.resize(n);
    for(ll& v : a) cin >> v;
    dfs(m, -1, (1 << 30) - 1);
    cout << ans;
    return 0;
}
