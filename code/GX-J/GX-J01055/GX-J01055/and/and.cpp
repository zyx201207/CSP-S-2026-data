#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long a[n],dp[m][n];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[1][i]=a[i];
    dp[2][1]=dp[1][1];
    dp[2][2]=dp[1][1]&a[2];
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }
    else{
        for(int i=2;i<=m;i++){
            for(int j=3;j<=n;j++){
                dp[i][j]=max(dp[i-1][j-1]&a[j],dp[i][j-1]);
            }
        }
        ans=dp[m][n];
    }
    cout<<ans;
    return 0;
}
