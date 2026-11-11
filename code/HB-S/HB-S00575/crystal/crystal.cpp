#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
int n, m;
ll a[maxn], dif[maxn];
int main(){
    
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i){
        dif[i] = a[i] - a[i - 1];
    }
    int l = 1, r = 1;
    ll sum = 0;
    int ans = 0;
    while(l <= r && r <= n){
        // cout << l << ' ' << r << ' ' << sum << '\n';
        while(r <= n && sum <= m){
            ++r;
            sum += 1LL * (r - l) * dif[r];
            // cout << l << ' ' << r << ' ' << sum << '\n';
        }
        ans = max(ans, r - l + 1);
        while(l <= r && sum > m){
            ++l;
            sum -= 1LL * (a[r] - a[l - 1]);
            // cout << l << ' ' << r << ' ' << sum << '\n';
        }
    }
    // cout << ansl << ' ' << ansr;
    cout << ans - 1 << '\n';
    return 0;
}