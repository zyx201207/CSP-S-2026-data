#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5 + 10;

ll n, m;
ll a[N];
ll s[N];

ll change(ll t, ll x, ll l, ll r){
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (s[mid - 1] - t * mid + x <= m) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
    for (ll r = 1; r <= n; r ++ ){
        ll x = a[r] * r - s[r - 1];
        ll l = change(a[r], x, 1, r);
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
