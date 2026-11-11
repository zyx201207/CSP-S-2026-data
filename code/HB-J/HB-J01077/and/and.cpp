#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,dp[200001],a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    memset(dp,-1,sizeof(dp));

    for(i=1;i<=n;i++){

        for(j=m;j>=1;j--){
            if(dp[j-1]==-1)dp[j]=max(dp[j],a[i]);
            else dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
