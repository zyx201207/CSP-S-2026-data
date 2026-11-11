#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
    LL p,d;
};
struct qu{
    LL s,t,d;
}r[100005];
struct cmp{
    bool operator()(node a,node b){
        return a.d>b.d;
    }
};
LL d[505][505],w[500005],hd[500005],xt[500005],t[500005],g[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(d,0x3f,sizeof(d));
    LL id,n,m,dd,qu,cur=0;scanf("%lld%lld%lld%lld%lld",&id,&n,&m,&dd,&qu);
    priority_queue<node,vector<node>,cmp> q;
    for(LL i=1;i<=m;++i)scanf("%lld",w+i);
    for(LL i=1;i<=n;++i){
        LL x;scanf("%lld",&x);
        for(LL j=1;j<=x;++j){
            LL y,v;scanf("%lld%lld",&y,&v);
            for(LL k=hd[y];k;k=xt[k]){
                d[i][g[k]]=min(d[i][g[k]],t[k]+v);
                d[g[k]][i]=min(d[g[k]][i],t[k]+v);
            }
            ++cur;
            t[cur]=v;
            g[cur]=i;
            xt[cur]=hd[y];
            hd[y]=cur;
        }
    }
    for(LL i=1;i<=n;++i){
        for(LL j=1;j<=n;++j){
            for(LL k=1;k<=n;++k){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    for(LL i=1;i<=qu;++i){
        LL x,y,nn=0x3f3f3f3f3f3f3f3fll;scanf("%lld%lld",&x,&y);
        for(LL j=hd[x];j;j=xt[j]){
            for(LL k=hd[y];k;k=xt[k]){
                nn=min(nn,d[g[j]][g[k]]+t[j]+t[k]);
            }
        }
        printf("%lld\n",nn+w[x]+w[y]);
    }
    return 0;
}
