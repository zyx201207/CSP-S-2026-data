#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, x[500005], f[500005], a[500005], k, c[500005];
bool fl[500005];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> x[i];
        f[x[i]]++;
    }
    sort(x + 1, x + n + 1);
    for(ll i = 1; i <= n; i++){
        if(f[x[i]] > 0 && !fl[x[i]]){
            a[++k] = x[i];
            fl[x[i]] = 1;
        }
    }
    for(ll i = 1; i < k; i++){
        c[i] = a[i + 1] - a[i];
    }
    ll t = 1, res = f[a[1]];
    for(ll i = 1; i < k; i++){
        ll s = 0, cnt = 0;
        if(c[i] <= c[i + 1]){
            res += f[a[i + 1]];
            for(ll j = t; j <= i + 1; j++){
                cnt += (a[i + 1] - a[j]);
            }
            if(m - cnt <= 0){
                break;
            }
            m -= cnt;
            s = cnt;
        }else{
            t = i;
        }
    }
    cout << res;
    return 0;
}
