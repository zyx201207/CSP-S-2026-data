#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> p(n), cf(n - 1);
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        p[i] = v;
    }
    for(int i = 1;i < n;i++) cf[i - 1] = p[i] - p[i - 1];
    ll sum = cf[0];
    ll number = 0;
    ll ans = 0;
    for(int i = 0;i < n - 1;i++) {
        if(((sum > cf[i] * number) && cf[i] != 0) || sum + cf[i] * number > m) {
            ans = max(ans, number);
            sum = cf[i];
            number = 1;
        } else {
            sum = sum + cf[i] * number;
            number++;
        }
    }
    ans = max(ans, number);
    cout << ans + 1;
    return 0;
}
