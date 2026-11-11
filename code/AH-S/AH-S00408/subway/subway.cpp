#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=510,M=2e5+10;//n条路线 m个站点
LL c,n,m,d,q,z,minn,t[N][M];
LL w[M],k[N],a[N][M],vis[N];
vector<LL> G[N];
void dfs(LL u,LL ans){
    if(minn<=ans) return ;
    if(u==z){
        minn=min(minn,ans);
        return ;
    }
    for(LL i=0;i<G[u].size();i++){
        LL v=G[u][i];
        if(!vis[v]&&u<k[v]){
            LL tmp=w[u]+t[v][u];
            vis[v]=1;
            for(LL j=u+1;j<=k[v];j++){
                dfs(a[v][j],ans+tmp);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(LL i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(LL j=1;j<=k[i];j++){
            scanf("%lld",&a[i][j]);
            scanf("%lld",&t[i][a[i][j]]);
            G[a[i][j]].push_back(i);
        }
    }
    LL u;
    while(q--){
        minn=1000000000000000001;
        scanf("%lld%lld",&u,&z);
        dfs(u,0);
        cout<<minn<<endl;
    }
    return 0;
}
