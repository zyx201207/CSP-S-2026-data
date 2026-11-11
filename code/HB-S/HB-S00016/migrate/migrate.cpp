#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, t;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(int pp=1;pp<=t;pp++){
        ll n, d, x[200005] = {0};
        cin >> n >> d;
        for(ll i=1;i<=n;i++){
            cin >> x[i];
        }
        ll tt=0;
        for(ll i=1;i<n;i++){
            ll ans = 10000000000000, cnt=0;
            for(ll j=i+1;j<=n;j++){
                bool kfc = true;
                for(ll k=i+1;k<=j;k++){
                    if(x[k]-x[k-1]>d) kfc = false;
                }
                if(!kfc) continue;
                ans = min(ans, x[j]-x[i]);
            }
            for(ll j=i+1;j<=n;j++){
                bool kfc = true;
                for(ll k=i+1;k<=j;k++){
                    if(x[k]-x[k-1]>d) kfc = false;
                }
                if(!kfc) continue;
                if(x[j]-x[i]==ans) cnt++;
            }
            if(cnt==2) tt++;
        }
        cout << tt << endl;
    }
    return 0;
}
