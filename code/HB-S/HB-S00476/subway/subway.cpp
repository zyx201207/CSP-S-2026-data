#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=550000;
int c,n,m,d,q;
int w_t[N];
struct Edge{
    int to,w,next;
}edge[N];
int head[N],num;
void add(int u,int v,int w){
    num++;
    edge[num].to=v;
    edge[num].w=w;
    edge[num].next=head[u];
    head[u]=num;
}
LL dis[N];
bool vis[N];
void dijk(int u){
    priority_queue<PII,vector<PII>,greater<PII>> q;//small to big
    dis[u]=0;
    q.push({0,u});
    while(!q.empty()){
        PII cmp=q.top();
        int z=cmp.second;
        q.pop();
        if(vis[z]) continue;
        vis[z]=1;
        for(int j=head[z];j;j=edge[j].next){
            int v=edge[j].to;
            if(dis[v]>dis[z]+edge[j].w){
                dis[v]=dis[z]+edge[j].w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w_t[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int cmp_to,cmp_w;
            scanf("%d%d",&cmp_to,&cmp_w);
            add(m+i,cmp_to,cmp_w);
            add(cmp_to,m+i,cmp_w);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=1;j<=m+n;j++){
            dis[j]=LONG_MAX;
            vis[j]=0;
        }
        dijk(x);
        LL ans=dis[y]+w_t[x]+w_t[y];
        printf("%lld\n",ans);
    }
    return 0;
}

