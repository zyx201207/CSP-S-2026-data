#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;

struct Edge{
    int to,val;
};

int c,n,m,d,q,w[N];
int k,a[N],t[N];
long long f[510][510];
vector<Edge> e[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&a[j]);
            scanf("%d",&t[j]);
        }
        for(int j=1;j<=k;j++) e[a[j]].push_back({i,t[j]});
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)
        for(int j=0;j<e[i].size();j++)
            for(int k=j+1;k<e[i].size();k++){
                int x=e[i][j].to,y=e[i][k].to,w=e[i][j].val+e[i][k].val;
                f[x][y]=f[y][x]=min(f[x][y],(long long)w);
            }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;
        long long ans=1e18;
        scanf("%d%d",&x,&y);
        for(Edge i:e[x])
            for(Edge j:e[y])
                ans=min(ans,w[x]+i.val+f[i.to][j.to]+j.val+w[y]);
        printf("%lld\n",ans);
    }
    return 0;
}
