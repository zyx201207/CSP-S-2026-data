#include <bits/stdc++.h>
using namespace std;
#define int long long
int cid,n,m,d,q;
int sum=0,w[500010];
//n路径数
//m点数
int k[510];
vector <int> a[510],t[510];
struct node{
    int u,w;
    bool operator <(const node &p) const{
        return p.w<w;
    }
}cur;
vector <node> g[1000010];
int dis[2010][2010];
void dijkstra(int st){
    for(int i=1;i<=m+sum;i++) dis[st][i]=1e18;
    dis[st][st]=0;
    priority_queue <node> q;
    q.push(node{st,0});
    while(!q.empty()){
        cur=q.top();
        q.pop();
        if(dis[st][cur.u]<cur.w) continue;
        for(node i:g[cur.u]){
            if(dis[st][i.u]>cur.w+i.w){
                dis[st][i.u]=cur.w+i.w;
                q.push(node{i.u,dis[st][i.u]});
            }
        }
    }
}

vector <pair<int,int>> bh[500010];
int W[510][510],jl[510][510];
void dijk(int st){
    priority_queue <node> q;
    q.push(node{st,0});
    for(int i=1;i<=n;i++) jl[st][i]=1e18;
    jl[st][st]=0;
    while(!q.empty()){
        cur=q.top();
        q.pop();
        if(jl[st][cur.u]<cur.w) continue;
        for(int i=1;i<=n;i++){
            if(jl[st][i]>cur.w+W[cur.u][i]){
                jl[st][i]=cur.w+W[cur.u][i];
                q.push(node{i,jl[st][i]});
            }
        }
    }
}
int MN[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
        sum+=k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++) bh[a[i][j]].push_back({i,t[i][j]});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) W[i][j]=1e18;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++){
            int u=a[i][j];
            for(pair<int,int> k:bh[u]){
                if(k.first==i) continue;
                W[i][k.first]=min(W[i][k.first],t[i][j]+k.second);
                W[k.first][i]=min(W[k.first][i],t[i][j]+k.second);
            }
        }
    }

    for(int i=1;i<=n;i++){
        dijk(i);
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y],add=1e18;
        for(pair<int,int> i:bh[x]){
            for(pair<int,int> j:bh[y]){
                add=min(add,jl[i.first][j.first]+i.second+j.second);
            }
        }
        cout<<ans+add<<"\n";
    }
    return 0;
}
