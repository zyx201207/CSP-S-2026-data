#include<bits/stdc++.h>
using namespace std;
int a[200005],\
dp[2][200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[0][i]=0x7fffffff;
    }
    dp[0][0]=d[1][0]=0;
    for(int i=0;i<m;++i){
        for(int j=1;j<=n;++j){
            dp[1][j]=max(dp[1][j-1],dp[0][j-1]&a[j]);
        }
        for(int i=0;i<=n;++i){
            dp[0][i]=dp[1][i];
        }
    }
    cout<<dp[1][n];
    
    return 0;
}