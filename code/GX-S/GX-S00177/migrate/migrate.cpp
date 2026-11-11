#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    vector<int> G(2000001);
    int dp[2000001];
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u]=v;
        }
        for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;i<n;j++){
                            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
        }
    }

}
