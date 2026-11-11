#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
int c,n,m,d,q1;
int a[500005];
int dis[500005];
int vis[500005];
vector<node>g[500505];
void spfa(int s){
    queue<int>q;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(node v:g[u]){
            if(v.v!=u&&dis[v.v]>dis[u]+v.w){
                q.push(v.v);
                dis[v.v]=dis[u]+v.w;
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q1);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int u,w;
            scanf("%d%d",&u,&w);
            g[m+i].push_back({u,w});
            g[u].push_back({m+i,w});
        }
    }
    //for(int i=1;i<=n;i++){
    //    spfa(m+i,i);
    //}
    for(int i=1;i<=q1;i++){
        int s,e;
        scanf("%d%d",&s,&e);
        memset(dis,0x3f,sizeof dis);
        spfa(s);
        printf("%d\n",(a[s]+dis[e]+a[e]));
    }
    return 0;
}
