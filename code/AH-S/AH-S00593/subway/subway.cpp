#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
    LL v,l;
};
vector<node>g[1010];
LL c,n,m,d,q,k,w[1010],a[510][1010],t[1010][510],y,dis[1010],ans;
void dfs(LL x){
    if(x==y)return;
    for(LL i=0;i<g[x].size();i++){
        if(dis[g[x][i].v]>dis[x]+t[x][g[x][i].l]+t[g[x][i].v][g[x][i].l]){
            dis[g[x][i].v]=dis[x]+t[x][g[x][i].l]+t[g[x][i].v][g[x][i].l];
            if(g[x][i].v==y)ans=min(ans,dis[y]+w[y]);
            dfs(g[x][i].v);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(LL i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&k);
        for(LL j=1;j<=k;j++)scanf("%lld%lld",&a[i][j],&t[a[i][j]][i]);
        for(LL j=1;j<=k;j++){
            for(LL l=1;l<=k;l++){
                if(j!=l)g[a[i][j]].push_back({a[i][l],i});
            }
        }
    }
    LL x;
    while(q--){
        scanf("%lld%lld",&x,&y);
        memset(dis,0x3f,sizeof dis);
        dis[x]=w[x],ans=0x3f3f3f3f3f3f3f3f;
        dfs(x);
        cout<<ans<<endl;
    }
    return 0;
}
