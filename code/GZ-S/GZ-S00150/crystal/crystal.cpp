//GZ-S00150遵义市第四中学周高逸

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, ans=1, fa=1, fb=1;
ll a[500005], d[500005], dp[500005];

ll f(ll x){
    ll dt=0, cnt=1;
    for(ll i=x+1; i<=n; i++){
        dt+=cnt*d[i];
        if(dt>m){
            dp[x] = cnt;
            break;
        }
        cnt++;
    }
    return cnt;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(ll i=1; i<=n; ++i){
        cin >> a[i];
        dp[i] = 1;
        if(a[i]!=i) fa = 0;
        if(i>=3){
            ll d = a[i-1] - a[i-2];
            if(a[i]-a[i-1]!=d) fb = 0;
        }
    }

    if(fa){
        ll s = 0;
        for(ll i=1; i<=n; ++i){
            s += i;
            if(s>m){
                cout << i;
                return 0;
            }
        }
    }
    else if(fb){
        ll s = 0, d = a[2]-a[1];
        for(ll i=1; i*d<=n; ++i){
            s += i*d;
            if(s>m){
                cout << i;
                return 0;
            }
        }
    }
    else{
        sort(a+1, a+n+1);
        d[1] = a[1];
        for(ll i=2; i<=n; ++i){
            d[i] = a[i]-a[i-1];
        }

        for(ll i=1; i<=n;)
            i+=f(i);
        for(ll i=1; i<=n; ++i)
            ans = max(ans, dp[i]);
        cout << ans;
        }

    return 0;
}
