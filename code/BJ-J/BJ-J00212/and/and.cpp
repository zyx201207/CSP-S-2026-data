#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(int j=2;j<=m;j++){
        for(int i=2;i<=n;i++){
            for(int k=1;k<i;k++){
                dp[i][j]=max(dp[i][j],dp[i-k][j-1]&a[i]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
