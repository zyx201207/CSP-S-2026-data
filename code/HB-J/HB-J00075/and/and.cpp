#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200005],cnt=INT_MIN,mx=INT_MIN;
int dp[4005][4005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0][0]=a[1];
    dp[1][0]=a[1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j],((j==1) ? a[i] : dp[i-1][j-1]) & a[i]);
        }
    }
    cout << dp[n][m];
    //cout << dp[2][1];
    return 0;
}
