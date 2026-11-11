#include <bits/stdc++.h>
using namespace std;
int dist[2005][2005];
int dp[2005][2005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=i;j++){
            if(dist[j]<dist[i]){
                dp[i][j]=dp[i+1][j+1];
            }else{
                dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[t];
    return 0;
}
