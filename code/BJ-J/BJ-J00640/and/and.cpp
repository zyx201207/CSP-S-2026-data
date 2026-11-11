#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf;
int n,m;
int a[200005];
int dp[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dp,-0x3f,sizeof(dp));
    inf=dp[0];
    dp[0]=0;
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(dp[j-1]!=inf){
                if(j==1){
                    dp[j]=max(dp[j],a[i]);
                    continue;
                }
                dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
            //cerr<<dp[1]<<" "<<endl;
        }
    }
    cout<<dp[m];
    return 0;
}
/*
idea:
1:n^2 dp
2:trie???
*/