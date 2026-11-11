/*
Find the number of the special island pairs.
#11 12 8pts -> 0pts???
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll c, t, n, d;
ll a[2000010];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(ll i = 1; i <= n; i++) cin >> a[i];

        ll q = a[2] - a[1];

        if(2 * q > d){
            cout << 0 << endl;
            continue;
        }

        ll ans = n - (d / q) - 1;

        if((d / q) % 2) ans--;

        if(ans < 0) ans = 0;

        cout << ans << endl;
    }

    return 0;
}
