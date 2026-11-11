#include<bits/stdc++.h>
using namespace std;
const int N=502,M=5e5+2;
const long long inf=0x7fffffffffffffff;
long long kksk[M],k[N],dp[N][N],a,sta[M][22][2],cnt[M],t;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c,n,m,d,q,u,v;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)dp[i][j]=((i==j)?0:inf);
    for(int i=1;i<=m;i++)cin>>kksk[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a>>t,sta[a][++cnt[a]][0]=i,sta[a][cnt[a]][1]=t;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<cnt[i];j++){
            for(int l=j+1;l<=cnt[i];l++){
                long long vanitas=sta[i][j][0],vanitatum=sta[i][l][0],omnia=sta[i][j][1],azusa=sta[i][l][1];
                dp[vanitas][vanitatum]=min(dp[vanitas][vanitatum],omnia+azusa),dp[vanitatum][vanitas]=dp[vanitas][vanitatum];
            }
        }
    }
    for(int l=1;l<=n;l++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(dp[i][l]!=inf&&dp[l][j]!=inf)dp[i][j]=min(dp[i][j],dp[i][l]+dp[l][j]);
            }
        }
    }
    while(q--){
        long long ans=inf;
        cin>>u>>v;
        for(int i=1;i<=cnt[u];i++)
            for(int j=1;j<=cnt[v];j++){
                long long nummm=dp[sta[u][i][0]][sta[v][j][0]],numm=sta[u][i][1]+sta[v][j][1]+nummm+kksk[u]+kksk[v];
                if(ans>numm&&nummm!=inf)ans=numm;
            }
        cout<<ans<<'\n';
    }
    return ( 0 - 0 );
}