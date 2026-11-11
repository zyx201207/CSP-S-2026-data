#include <bits/stdc++.h>
using namespace std;
const int N=500+5;
const int M=5e5+5;
void work(){
    int x,y;
    scanf("%d%d",&x,&y);
    //x-> # -> 0 -> y;
    //ans=w[x]+w[y]+....
}
struct Node{
    int x,cost;
};
vector<Node> G[N];
int w[M];
int k[N];
int ans=1e9;
bool vis[M];
void DFS1(int u,int en,int res){
    if (res>ans) return ;
    if (u==en){
        ans=min(ans,res);
        return ;
    }
    for (Node nx:G[u]){
        int v=nx.x;
        if (!vis[v]){
            vis[v]=true;
            DFS1(v,en,res+nx.cost);
            vis[v]=false;
        }
    }
}
int c,n,m,d,q;
void solve1(){
    ans=1e9;
    for (int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int x,y,o,z;
        if (k==1) scanf("%d%d",&x,&y);
        if (k==2){
            scanf("%d%d",&x,&o);
            scanf("%d%d",&y,&z);
            G[x].push_back({y,o+z});
            G[y].push_back({x,o+z});
        }
    }
    for (int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ans=1e9;
        memset(vis,false,sizeof vis);
        vis[x]=true;
        DFS1(x,y,0);
        printf("%lld\n",w[x]+w[y]+ans);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++) scanf("%d",&w[i]);
    //if (7<=c && c<=11) solve1();
    solve1();
    return 0;
}
