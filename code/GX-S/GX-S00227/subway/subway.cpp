#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,d,qn,n;
int w[500005];
int t;
//dij
struct edge{
    int v,w;
};
vector<edge> e[1000005];
struct node{
    int dis,u;
    bool operator>(const node&a)const{return dis>a.dis;}
};
void add(vector<edge> a){
    int fl=0;
    for(auto ed:a){
        e[++t].push_back(ed);
        e[ed.v].push_back({t,ed.w});
        if(fl){
        e[t].push_back({t-1,0});
        e[t-1].push_back({t,0});
        }
        fl=1;
    }
    return ;
}
priority_queue<node,vector<node>,greater<node>> q;
vector<int> dis[1000005];
int vis[1000005];
void dij(int s,int tim){
    dis[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]==tim) continue;
        vis[u]++;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(vis[v]==tim) continue;
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                q.push({dis[s][v],v});
            }
        }
    }
}
vector<edge> edg;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>c>>n>>m>>d>>qn;
    for(int i=1;i<=m*(n+1);i++)
        for(int j=1;j<=m*(n+1);j++)
            dis[i].push_back(1e18);
    t=m;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        int qi,aa,t;
        for(int j=1;j<=k;j++){
                cin>>aa>>t;
            edg.push_back({aa,t});
        }
        add(edg);
        edg.clear();
    }
/*
    for(int i=1;i<=t;i++){
    for(auto ed:e[i]){
        cout<<ed.v<<' '<<ed.w<<'\n';
    }
    cout<<'\n';
    }*/
    int x,y;
    for(int i=1;i<=qn;i++){
        cin>>x>>y;
        //cout<<x<<' '<<y<<'\n';
        if(dis[x][y]==1e18)dij(x,i);/*
        for(int i=1;i<=t;i++)
            cout<<dis[x][i]<<' ';*/
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }

    return 0;
}
