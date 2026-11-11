#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define gc getchar
using namespace std;

const int N=5e2+10,M=5e5+10;
int tid,n,m,q,w[M];
LL g[N][N];
vector<pair<int,int>>e[M];

int rd(){
    int x=0;char ch=gc();
    while(!isdigit(ch))ch=gc();
    while(isdigit(ch))x=x*10+ch-'0',ch=gc();
    return x;
}
void Min(LL &x,LL y){if(y<x)x=y;}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    tid=rd();n=rd();m=rd();rd();q=rd();
    for(int i=1;i<=m;i++)w[i]=rd();
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++){
        int c,x,y;c=rd();
        g[i][i]=0;
        while(c--){
            x=rd();y=rd();
            e[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++)
        for(int x=0;x<e[i].size();x++)
            for(int y=x+1;y<e[i].size();y++){
                int u=e[i][x].fi,v=e[i][y].fi,wu=e[i][x].se,wv=e[i][y].se;
                Min(g[u][v],wu+wv);
                Min(g[v][u],wu+wv);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                Min(g[i][j],g[i][k]+g[k][j]);
    while(q--){
        int x=rd(),y=rd();
        LL ans=1e18;
        for(auto i:e[x])for(auto j:e[y])
            ans=min(ans,g[i.fi][j.fi]+i.se+j.se);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}