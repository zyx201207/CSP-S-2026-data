#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[5005],k[505],a,t,dp[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=m+n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            dp[a][m+i]=t;
            dp[m+i][a]=t;
        }
    }
    for(int i=1;i<=m+n;i++){
        dp[i][i]=0;
    }
    bool flag=false;
    while(flag==false){
        flag=true;
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                for(int mid=1;mid<=m+n;mid++){
                    if(dp[mid][i]!=-1&&dp[mid][j]!=-1){
                        if(dp[i][j]>dp[mid][i]+dp[mid][j]||dp[i][j]==-1){
                            flag=false;
                            dp[i][j]=dp[j][i]=dp[mid][i]+dp[mid][j];
                        }
                    }

                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
