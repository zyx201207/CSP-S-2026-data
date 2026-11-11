#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =5005;

int dp[N][N],x[N];

void solve(){
    memset(dp,0,sizeof(dp));
    int n ,d; cin >> n >> d;
    ll ans =0,mi = 1e18;
    for(int i  = 1 ;i <=n;i++) cin >> x[i];
    for(int len = 0 ; len <= d;len++)dp[0][len] = -1;
    for(int i = d ; i<=n;i++){
        for(int len = d ; len > 0;len--){
            dp[i][len] += dp[i-len][len-1] + 1;
            }
        }


    for(int j = 1; j<=n;j++){
            ll tmp = 0;
        for(int i = 1; i<=n;i++){
            if(dp[i][j] == 2) tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans << '\n';

}

int main(){
    cin.tie(nullptr),ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c; cin >> c >> t;
    while(t--) solve();
    return  0;
}
