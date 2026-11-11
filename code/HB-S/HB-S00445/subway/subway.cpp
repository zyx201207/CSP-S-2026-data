#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
    int nxt,to,val;
};
struct point{
    int id,x;
};
node edge[2000005];
int c,d,qq;
int head[300005];
int dis[2005][2005];
int w[300005];
bool b[300005];
int e_num;
int knum;
void addedge(int u,int v,int val){
    edge[++e_num].to=v;
    edge[e_num].nxt=head[u];
    edge[e_num].val=val;
    head[u]=e_num;
}
bool operator < (point x,point y){
    return x.x>y.x;
}
void dijk(int s){
    priority_queue<point> q;
    while(!q.empty())q.pop();
    dis[s][s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().id;
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(dis[s][u]+edge[i].val<dis[s][v]){
                dis[s][v]=dis[s][u]+edge[i].val;
                q.push({v,dis[s][v]});
            }
        }
    }
}
int T;
int ans;
void bfs(int s,int op){
    queue<point> q;
    while(!q.empty())q.pop();
    q.push({s,0});
    memset(b,0,sizeof(b));
    while(!q.empty()){
        int u=q.front().id;
        int p=q.front().x;
        q.pop();
        if(u==op){
            ans=p;
            return ;
        }
        if(b[u]){
            continue ;
        }
        b[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(u>n&&v>n)q.push({v,p});
            else q.push({v,p+1});
        }


    }
}
void solve(int u,int v){
    bfs(u,v);
    cout<<ans*T+w[u]+w[v]<<'\n';
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>m>>n>>d>>qq;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    knum=n;
    for(int i=1;i<=m;i++){
        int k,u,v;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>u>>v;
            T=v;
            addedge(j+knum,u,v);
            addedge(u,j+knum,v);
            if(j!=1)addedge(knum+j,knum+j-1,0);
            if(j!=1)addedge(knum+j-1,knum+j,0);
//            cout<<knum+j<<' '<<u<<'\n';
        }
        knum+=k;
    }
    int u=0,v=0;
    if(12<=c&&c<=15){
        while(qq--){
            cin>>u>>v;
            solve(u,v);
        }

    }
    else {
        for(int i=1;i<=qq;i++){
 //           cout<<i<<' ';
            cin>>u>>v;
            if(b[u])cout<<dis[u][v]+w[u]+w[v]<<'\n';
            else if(b[v])cout<<dis[v][u]+w[u]+w[v]<<'\n';
            else {
                dijk(u);
                b[u]=1;
                cout<<dis[u][v]+w[u]+w[v]<<'\n';
            }
        }
    }
    return 0;
}
