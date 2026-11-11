#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
struct node{
    long long id,t;
};
//vector<node>g[600];
vector<node>gg[500010];
inline bool cmp(node x,node y){
    return x.id<y.id;
}/*
inline long long get(long long l,long long r,long long x,long long j){
    long long best=-1;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(g[j][mid].id<=x){
            best=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return best;
}*/
long long dis[600][600],w[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);//m zhan tai
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
    }
    for(long long i=1,a,tt,k;i<=n;i++){//n xian lu
        scanf("%lld",&k);
        while(k--){
            scanf("%lld%lld",&a,&tt);
            node it;
            it.id=a,it.t=tt;
            //g[i].push_back(it);//lu->tai
            gg[a].push_back({i,tt});//tai->lu

        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<gg[i].size();j++){
            for(int k=j+1;k<gg[i].size();k++){
                long long p1=gg[i][j].id,p2=gg[i][k].id;
                dis[p1][p2]=dis[p2][p1]=min(dis[p1][p2],gg[i][j].t+gg[i][k].t);
            }
        }
    }
    /*
    //for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end(),cmp);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int last=0,len=g[j].size();
            for(int ii=0;ii<g[i].size();ii++){
                long long jj=get(last,len,g[i][ii].id,j);
                if(jj==-1)continue;
                if(g[j][jj].id==g[i][ii].id)dis[i][j]=dis[j][i]=min(dis[i][j],g[i][ii].t+g[j][jj].t);
                last=jj+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" \n"[j==n];
        }
    }
    */
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
    while(q--){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        long long res=1e18;
        for(int i=0;i<gg[x].size();i++)for(int j=0;j<gg[y].size();j++){
            long long p1=gg[x][i].id,p2=gg[y][j].id;
            res=min(res,dis[p1][p2]+gg[x][i].t+gg[y][j].t);
        }
        printf("%lld\n",w[x]+w[y]+res);
    }
    return 0;
}
