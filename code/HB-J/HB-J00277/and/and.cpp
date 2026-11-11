#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++) dp[i][1]=a[i-1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[1][j]=max(dp[1][j],dp[i][j]);
            for(int j2=1;j2<=i-1;j2++){
                dp[i][j]=max(dp[i][j],dp[j2][j-1]&a[i-1]);
            }
        }
        for(int j=i+1;j<n;j++){
            dp[i][j]=0;
        }
    }
    cout<<dp[n][m];
    return 0;
}
