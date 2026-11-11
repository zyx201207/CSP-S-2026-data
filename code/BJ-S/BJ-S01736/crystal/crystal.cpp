#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 5e5 + 5;
ull n, m;
ll a[N], s[N];
ll l, r, ans;

int check(ll x) {
    for(ll i = x; i <= n; i++) {
        ll q = x * a[i];
        ll p = s[i] - s[i - x];
        if((ull)(q - p) <= m) {
            //cout << x << " " << q - p << endl;
            return true;
        }
    }
    return false;
}

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    l = 0;
    r = n;
    for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i]; //前缀和

    while(l <= r) { //可以用mid个小水晶合成大水晶
        ll mid = (l + r) / 2;
        if(check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;

    return 0;
}
