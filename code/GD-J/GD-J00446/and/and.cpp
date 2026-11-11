#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2090;
int dp[N][N],n,m,a[N];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        dp[i][1] = a[i];
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            for(int k = 2;k<=m;k++){
                dp[i][k] = max(dp[i][k],a[i] & dp[j][k-1]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) ans = max(ans,dp[i][m]);
    cout<<ans;

    return 0;
}