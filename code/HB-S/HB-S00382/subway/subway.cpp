#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,u,w,id,nxt;
};
node edge[50005]={0};
int c,n,m,d,q,cnt=0,head[50005]={0};
bool vis[50005]={0};
int minlong=2e9;
int sp[20005]={0};
void add_edge(int u,int v,int w,int id){
    edge[++cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].id=id;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int all,int id,int eq){
    if(all>=minlong){return;}
    if(u==eq){minlong=min(minlong,all);}
    for(int i=head[u];i!=0;i=edge[i].nxt){
        if(vis[edge[i].v]==0&&((edge[i].id==0||id==0)||edge[i].id==id)){
            vis[edge[i].v]=1;
            dfs(edge[i].v,all+edge[i].w,edge[i].id,eq);
            vis[edge[i].v]=0;
        }
    }
}
int add_fp(int u,int kj){
    for(int i=head[u];i!=0;i=edge[i].nxt){
        if(edge[i].v==kj){
            return edge[i].w;
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){cin>>sp[i];}
    for(int i=1;i<=n;i++){
        int k,las,a,b;
        cin>>k>>a>>b;
        add_edge(a,0,b,0);
        add_edge(0,a,b,0);
        for(int j=2;j<=k;j++){
            las=a;
            cin>>a>>b;
            add_edge(a,0,b,0);
            add_edge(0,a,b,0);
            add_edge(las,a,0,i);
            add_edge(a,las,0,i);
        }
    }
    for(int i=1;i<=q;i++){
        int e,g;
        cin>>e>>g;
        memset(vis,0,sizeof(vis));
        minlong=2e9;
        dfs(e,0,0,g);
        cout<<sp[e]+sp[g]+add_fp(0,e)+add_fp(g,0)+minlong<<'\n';
    }
    return 0;
}
