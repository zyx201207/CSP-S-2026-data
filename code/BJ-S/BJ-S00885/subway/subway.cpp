#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
long long c,n,m,d,q;
long long ww[M];
long long g[M];
struct nod{
    long long line,t;
}tmp;
vector<nod>sta[M];
long long floyd[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(i!=j){
                floyd[i][j]=0x3f3f3f3f3f3f3f;
            }
        }
    }
    for(long long i=1;i<=m;i++){
        scanf("%lld",&ww[i]);
    }
    for(long long i=1;i<=n;i++){
        tmp.line=i;
        scanf("%lld",&g[i]);
        for(long long j=1;j<=g[i];j++){
            long long a1;
            scanf("%lld%lld",&a1,&tmp.t);
            long long l1=sta[a1].size();
            for(long long t=0;t<l1;t++){
                floyd[i][sta[a1][t].line]=floyd[sta[a1][t].line][i]=min(floyd[i][sta[a1][t].line],sta[a1][t].t+tmp.t);
            }
            sta[a1].push_back(tmp);
        }
    }
    for(long long t=1;t<=n;t++){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                floyd[i][j]=min(floyd[i][j],floyd[i][t]+floyd[t][j]);
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        printf("%lld ",floyd[i][j]);
    //    }
    //    printf("\n");
    //}
    for(long long i=1;i<=q;i++){
        long long u,v;
        scanf("%lld%lld",&u,&v);
        long long mi=0x3f3f3f3f3f3f3f;
        long long l1=sta[u].size();
        long long l2=sta[v].size();
        long long aa,bb,cc;
        for(long long j=0;j<l1;j++){
            for(long long t=0;t<l2;t++){
                //long long ti=mi;
                long long b=ww[u]+sta[u][j].t+ww[v]+sta[v][t].t;
                mi=min(mi,floyd[sta[u][j].line][sta[v][t].line]+b);
                //if(mi<ti){
                //    aa=sta[u][j].t;
                //    bb=sta[v][t].t;
                //    cc=floyd[sta[u][j].line][sta[v][t].line];
                //}
            }
        }
        printf("%lld\n",mi);
        //printf("%lld %lld\n",ww[u],ww[v]);
        //printf("%lld %lld\n",aa,bb);
        //printf("!!%lld\n",cc);
    }
    return 0;
}

