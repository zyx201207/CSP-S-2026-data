#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
#define ll long long
ll w[N];
struct node{
    int v;
    ll w;
    friend bool operator < (node x,node y){
        return x.w>y.w;
    }
};
node fil(int v,ll w){
    node tmp;
    tmp.v=v;
    tmp.w=w;
    return tmp;
}
vector<node> p[N];
ll edge[M][M];
priority_queue <node> pq;
bool vis[M];
ll f[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int v;
            ll w;
            scanf("%d %lld",&v,&w);
            p[v].push_back(fil(i,w));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                edge[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(node u : p[i]){
            for(node v : p[i]){
                if(u.v!=v.v){
                    edge[u.v][v.v]=min(edge[u.v][v.v],u.w+v.w);
                }
            }
        }
    }
    for(int s=1;s<=n;s++){
        while(!pq.empty()) pq.pop();
        for(int i=1;i<=n;i++){
            vis[i]=false;
            f[s][i]=1e18;
        }
        f[s][s]=0;
        pq.push(fil(s,0));
        while(!pq.empty()){
            int u=pq.top().v;
            pq.pop();
            vis[u]=true;
            for(int v=1;v<=n;v++){
                if(f[s][u]+edge[u][v]<f[s][v]&&!vis[v]){
                    f[s][v]=f[s][u]+edge[u][v];
                    pq.push(fil(v,f[s][v]));
                }
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edge[i][j]>=1e18) printf("inf ");
            else printf("%lld ",edge[i][j]);
        }
        printf("\n");
    }
    */
    /*
    for(int i=1;i<=m;i++){
        for(node v : p[i]){
            printf("%d ",v.v);
        }
        printf("\n");
    }
    printf("nxt\n");
    */
    for(int i=1;i<=q;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        ll ans=1e18;
        for(node x : p[u]){
            //printf("%d\n",x.v);
            for(node y : p[v]){
                //printf("%d %d\n",x.v,y.v);
                ans=min(ans,f[x.v][y.v]+x.w+y.w);
            }
        }
        printf("%lld\n",ans+w[u]+w[v]);
    }
}
