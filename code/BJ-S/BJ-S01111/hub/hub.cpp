#include<bits/stdc++.h>
using namespace std;
#define maxn 100'0005
#define int long long
struct edge{
    int to,next;
}e[maxn<<1];
int n,k,h[maxn],tot,dis[2][maxn],num[2][maxn];
bool vis[2][maxn];
void addedge(int u,int v){
    e[++tot].to=v;
    e[tot].next=h[u];
    h[u]=tot;
    return;
}
void dfs(int id,int x){
    for(int i=h[x];i;i=e[i].next){
        if(vis[id][e[i].to]){
            continue;
        }
        dis[id][e[i].to]=dis[id][x]+1;
        dfs(id,e[i].to);
    }
    return;
}
void dfs2(int id,int x,int fa){
    num[id][dis[1][x]]++;
    for(int i=h[x];i;i=e[i].next){
        if(e[i].to==fa||dis[0][e[i].to]>dis[1][e[i].to]){
            continue;
        }
        dfs(id,e[i].to);
    }
    return;
}
signed main(){
    int c,t;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            addedge(u,v);
            addedge(v,u);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    vis[k]=false;
                    dis[0][k]=dis[1][k]=0x3f3f3f3f;
                    num[0][k]=num[1][k]=0x3f3f3f3f;
                }
                vis[0][i]=vis[1][j]=true;
                dfs(0,i);
                dfs(1,j);
                for(int k=h[i];k;k=e[k].next){
                    dfs2(0,e[k].to,0);
                }
                
            }
        }
    }
    return 0;
}