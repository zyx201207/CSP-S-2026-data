#include <bits/stdc++.h>
using namespace std;


int c;
int n/*line*/,m/*point*/,d,q;

int p[5*100000+10];
int f[500+10][5*100000+10];
long long dp[500+10][500+10];
vector<int> cr[500+10];
vector<int> hc[5*100000+10];


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x,y;scanf("%d%d",&x,&y);
            f[i][x]=y;
            cr[i].push_back(x);
            hc[x].push_back(i);
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<hc[i].size();j++){
            for(int k=j+1;k<hc[i].size();k++){
                int x=hc[i][j],y=hc[i][k];
                long long tmp=dp[x][y];
                dp[x][y]=dp[y][x]=min(tmp,(long long)f[x][i]+f[y][i]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dp[j][i]=dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        long long ans=0x7f7f7f7f7f7f7f7f;
        for(auto x:hc[u]){
            for(auto y:hc[v]){
                ans=min(ans,f[x][u]+dp[x][y]+f[y][v]);
            }
        }
        printf("%lld\n",ans+p[u]+p[v]);
    }
    return 0;
}
/*
shen jing ti mu,N shi xian,M shi dian
Floid???

*/
