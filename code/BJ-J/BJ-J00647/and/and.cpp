#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[200005];
ll ann[200005];
vector<ll> b[200005];
bool Find(ll x, ll y) {
    ll k = 0;
    for(int i = 0;i < b[y].size();i++) {
        if(b[y][i] == x) {
            k = 1;
            break;
        }
    }
    return (k == 1);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++) {
        cin >> a[i];
        ann[i] = a[i];
        b[i].push_back(a[i]);
    }
    ll ans = -2000000000;
    for(ll i = 2;i <= m;i++) {
        for(ll j = 1;j <= n;j++) {
            ll now = -1000000000;
            for(ll k = 1;k <= n;k++) {
                if(j == k || Find(a[k], j)) {
                    continue;
                }
                if(now < ann[j] & a[k]) {
                    b[j].push_back(a[k]);
                }
                now = max(now, ann[j] & a[k]);
                //cout << "i = " << j << " j = " << k << " now = " << now << endl;
            }
            ann[j] = now;
        }
    }
    for(ll i = 1;i <= n;i++) {
        ans = max(ans, ann[i]);
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
