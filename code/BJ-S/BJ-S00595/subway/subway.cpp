#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T;
int w[500005],k[500005],a,b;
long long dp[505][505],ans;
struct xxs{
    int x,t;
};
vector<xxs> q[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a,&b);
            q[a].push_back({i,b});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e14+7;
        }
    }
    for(int i=1;i<=n;i++) dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<q[i].size();j++){
            for(int k=j+1;k<q[i].size();k++){
                dp[q[i][j].x][q[i][k].x]=min(dp[q[i][j].x][q[i][k].x],q[i][j].t+q[i][k].t+0ll);
                dp[q[i][k].x][q[i][j].x]=dp[q[i][j].x][q[i][k].x];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(T--){
        scanf("%d%d",&a,&b);
        ans=1e14+7;
        for(int i=0;i<q[a].size();i++){
            for(int j=0;j<q[b].size();j++){
                ans=min(ans,dp[q[a][i].x][q[b][j].x]+q[b][j].t+q[a][i].t+w[a]+w[b]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}