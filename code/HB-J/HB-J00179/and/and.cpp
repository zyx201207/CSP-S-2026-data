#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(long long i = 1;i <= n;i++){
        dp[i] = a[i];
    }
    for(long long i = 2;i <= m;i++){
        for(long long j = n;j >= i;j--){
            dp[j] = max(dp[j - 1],(dp[j - 1] & a[j]));
        }
        dp[i] = dp[i - 1] & a[i];
        for(long long j = i - 1;j >= 0;j--){
            dp[j] = 0;
        }
    }
    cout << dp[n];
    return 0;
}
/*
ding yi dp[i][j] biao shi zai qian j ge shu zhong xuan ze i ge
shu shi de ta men an wei yu de zhi zui da

tui dao gong shi:
dp[i][j] = max{dp[i - 1][j - 1] and a[j],dp[i][j - 1]}
*/
