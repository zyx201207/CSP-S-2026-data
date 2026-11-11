#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lx LONG_MAX
#define ln LONG_MIN
const int qq = 2e5+10;
ll a[qq],n,m,aa;
ll dp[20000][2000];
ll zand = (1>>20)-1;
bool fga = 1;

bool cka(ll x){
    while(x >= 1){
        if(!(x%2)){fga = 0;return 0;}
        x /= 2;
    }
}
bool ckb(){
    int c1 = 0;
    ll nn = n;
    while(nn >= 1){
        c1 += (nn%2);
        nn /= 2;
    }if(c1 != 1)return 0;
    for(int i = 1;i <= n;i ++){
        if(a[i] != (i-1)) return 0;
    }return 1;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> aa;
        cka(aa);
        a[i] = aa;
        zand &= aa;
    }sort(a+1,a+1+n);

    if(m == 1){cout << a[n];return 0;}
    if(m == n){cout << zand;return 0;}
    if(fga){cout << a[n-m+1];return 0;}
    ll ans = -1;
    if(m == 2){
        for(int i = 1;i < n;i ++){
            ans = max(ans,(a[i]&a[i+1]));
        }cout << ans;return 0;
    }
    if(ckb()){
        ll res = 0;
        for(int i = 1;i <= n-m+1;i ++){
            res ^= a[i];
        }cout << res;return 0;
    }
    if(m == n-1){
        for(int i = 1;i <= n;i ++){
            ans = max(ans,(zand^a[i]));
        }cout << ans;return 0;
    }
    for(int i = 1;i <= n;i ++) dp[i][1] = a[i];
    for(int j = 2;j <= m;j ++){
        for(int i = 1;i <= n;i ++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }cout << dp[n][m];
    return 0;
}
