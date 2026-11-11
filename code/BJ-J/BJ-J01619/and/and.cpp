#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll cnt[55];
bool s[200005][55];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;
    cin >> n >> k ;
    for(int i = 1; i <= n; i++){
        cin >> a[i] ;
        ll t = a[i];
        for(int p = 30; p >= 0; p--){
            ll q = (1 << p);
            if(t >= q){
                s[i][p] = 1;
                t -= q;
                cnt[p]++;
            }
            else{
                s[i][p] = 0;
            }
        }
    }
    ll ans = 0;
    for(int i = 30; i >= 0; i--){
        if(cnt[i] >= k){
            ans += (1ll << i);
            for(int j = 1; j <= n; j++){
                if(s[j][i] == 0){
                    for(int k = i-1; k >= 0; k--){
                        if(s[j][k] == 1){
                            s[j][k] = 0;
                            cnt[k]--;
                        }
                    }
                }
            }
        }
    }
    cout << ans ;
    return 0;
}
