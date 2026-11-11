#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=505,K=2e4+5,M=N*(N+1)/2+5,INF=0x3f3f3f3f3f3f3f3f;
LL c,n,m,d,q;
LL w[M];
LL k[N],a[N][K],t[N][K];
LL nxt[M][N];
vector<LL> g[N];
//a--kou ting
//t--ting zhan
//wz--(1,kou) (2,ting) (3,zhan)
LL xr,yr,minn=INF;
void dfs(LL xr,LL wz,LL sum,LL hx,LL zbz){
    if(xr==yr&&wz==2){
        //ting->kou
        sum+=w[xr];
        minn=min(minn,sum);
        return ;
    }
    //kou->ting
    if(wz==1) dfs(xr,2,sum+w[xr],hx,0);
    if(wz==2){
        //ting->tai
        for(LL i=0;i<g[xr].size();i++){
            if(nxt[g[xr][i]][xr]!=-1)
                if(g[xr][i]!=hx)
                    dfs(xr,3,sum+t[g[xr][i]][xr],hx,g[xr][i]);
                else dfs(xr,3,sum-t[g[xr][i]][xr],hx,g[xr][i]);
        }
    }
    if(wz==3){
        //tai->tai
        if(zbz!=0) dfs(nxt[zbz][xr],3,sum,zbz,0);
        //tai->ting
        else dfs(xr,2,sum+t[hx][xr],hx,0);
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(LL i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(LL j=1;j<=k[i];j++) {
            scanf("%lld",&a[i][j]);
            scanf("%lld",&t[i][a[i][j]]);
            nxt[i][a[i][j-1]]=a[i][j];
            g[a[i][j]].push_back(i);
        }
        nxt[i][a[i][k[i]]]=-1;
    }
    while(q--){
        scanf("%lld %lld",&xr,&yr);
        minn=INF;
        dfs(xr,1,0,0,0);
        printf("%lld\n",minn);
    }
    return 0;
}
