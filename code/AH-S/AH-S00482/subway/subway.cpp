#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=1e5+10;
struct Node{
    LL v,w;
};
LL n,m,d,q,w[M],k[510],a[510][M],t[510][M],dis[M];
vector<Node>G[M];
void djs(LL s){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    for(LL i=1;i<=n;i++){
        LL minn=0x7f7f7f7f7f7f7f7f;
        for(LL j=0;j<G[i].size();j++){
            LL w=G[i][j].w,v=G[i][j].v;
            if(dis[i]+)
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    LL c;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&n,&d,&q);
    for(LL i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(LL j=1;j<=k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
        }
    }
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=k[i];j++){
            for(LL p=j+1;p<=k[i];p++){
                G[j].push_back({p,t[i][j]+t[i][p]});
                G[p].push_back({j,t[i][j]+t[i][p]});
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&u,&v);
        djs(u);
        printf("%lld\n",&dis[v]);
    }
    return 0;
}
