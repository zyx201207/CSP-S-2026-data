#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=500005;
int mp[505][MAXN];
int w[MAXN];
int inf=0x3f3f3f3f;
int k[MAXN];
int a[505][MAXN];
int head[MAXN],to[MAXN],nxt[MAXN],cnt;
int val[MAXN];
void add_edge(int u,int v,int h){
    cnt++;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
    val[cnt]=h;
    return;
}
int dis[MAXN];
struct node{
    int u,dis;
    bool operator < (const node &c) const{
        return dis<c.dis;
    }
};
priority_queue<node> pq;
int vis[MAXN];
void dij(int s,int t){
    dis[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        node tmp=pq.top();
        pq.pop();
        int u=tmp.u;
        //cout<<u<<"!"<<tmp.dis<<"\n";
        //if (u==t){
            //return;
        //}
        //if (vis[u]==1){
            //continue;
        //}
        vis[u]=1;
        for (int i=head[u];i!=0;i=nxt[i]){
            int v=to[i];
            if (dis[v]>dis[u]+val[i]){
                dis[v]=dis[u]+val[i];
                pq.push({v,dis[v]});
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(mp,inf,sizeof(mp));
    for (int i=1;i<=n;i++){
        mp[i][i]=0;
    }
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>mp[i][j];
        }
        for (int j=1;j<=k[i];j++){
            for (int z=1;z<=k[i];z++){
                add_edge(a[i][j],a[i][z],mp[i][z]+mp[i][j]);
                //cout<<a[i][j]<<" "<<a[i][z]<<" "<<mp[i][z]+mp[i][j]<<"\n";
            }
        }
    }
    for (int z=1;z<=q;z++){
        int x,y;
        cin>>x>>y;
        for (int i=1;i<=m;i++){
            dis[i]=inf;
            vis[i]=0;
        }
        dij(x,y);
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
return 0;
}
