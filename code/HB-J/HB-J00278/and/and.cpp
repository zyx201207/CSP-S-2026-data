#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],dp[2005][2005];
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=a[i];
        for(int j=2;j<=min(m,j);j++){
            for(int k=j-1;k<i;k++){
                dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans=max(ans,dp[i][m]);
    }
    cout<<ans;
    return 0;
}
