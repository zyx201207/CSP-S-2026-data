#include<bits/stdc++.h>
const int N=500,M=5e5;
const long long inf=1e18;
int caseid,n,m,d,q;
int w[M+5];
struct node{
    int x,t;
};
std::vector<node>vc[N+5];
std::vector<node>vt[M+5];
long long dis[N+5][N+5];
void cmin(long long &x,long long y){x>y?x=y:0;}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&caseid,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)scanf("%d",&w[i]);
    for(int i=1,le;i<=n;++i){
        scanf("%d",&le);
        for(int j=1,x,t;j<=le;++j){
            scanf("%d%d",&x,&t);
            //if(i==1)printf("%d %d\n",x,t);
            vc[i].push_back((node){x,t});
            vt[x].push_back((node){i,t});
            //if(x==2)printf("%d %d %d\n",x,i,t);
        }
    }
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        if(i!=j)dis[i][j]=inf;
    }
    for(int i=1;i<=n;++i){
        for(node j:vc[i]){
            for(node k:vt[j.x]){
                cmin(dis[i][k.x],j.t+k.t);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=q;++i){
        scanf("%d%d",&x,&y);
        long long ans=inf;
        for(node j:vt[x]){
            for(node k:vt[y]){
                //if(dis[j.x][k.x]+j.t+k.t==6){
                //    printf("%d %d\n",j.x,k.x);
                //    printf("%d %d\n",j.t,k.t);
                //}
                cmin(ans,dis[j.x][k.x]+j.t+k.t);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    //printf("%d\n",tm);
    return 0;
}