#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e4+5;
struct edge {
    int v,w;
};
struct node {
    int dis,u;
    bool operator >(const node &x) const {
        return dis>x.dis;
    }
};
int c,n,m,d,Q,W[maxm],a[maxm],t[maxm];
unordered_map<int,int> dis;
unordered_map<int,bool> vis;
// int dis[3*maxm];
// bool vis[3*maxm];
vector<edge> g[550*maxm];
priority_queue<node,vector<node>,greater<node>> q;
// int pre[3*maxm];
//1~mµØÌú¿Ú m+1~2mÕ¾Ìü 2m+1~2m+dÕ¾Ì¨
void dijkstra(int s) {
    // memset(vis,false,sizeof(vis));
    // memset(dis,0x3f,sizeof(dis));
    for (int i=1;i<=(3+n)*m;i++)
        vis[i]=false,dis[i]=1e18;
    q.push({0,s}),dis[s]=0;
    while (!q.empty()) {
        int u=q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (auto [v,w]:g[u])
            if (dis[u]+w<dis[v]) dis[v]=dis[u]+w/*,pre[v]=u*/,q.push({dis[v],v});
    }
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for (int i=1;i<=m;i++) {
        cin>>W[i];
        g[i].push_back({m+i,W[i]});
        g[m+i].push_back({i,W[i]});
    }
    // int i*m=0;
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            cin>>a[j]>>t[j];
            g[m+a[j]].push_back({2*m+i*m+a[j],t[j]});
            g[2*m+i*m+a[j]].push_back({m+a[j],t[j]});
            if (j>=2) {
                g[2*m+i*m+a[j]].push_back({2*m+i*m+a[j-1],0});
                g[2*m+i*m+a[j-1]].push_back({2*m+i*m+a[j],0});
            }
        }
        // i*m=k;
    }
    // cout<<"graph:"<<'\n';
    // for (int i=1;i<=(n+5)*m;i++)
    //     if (!g[i].empty()) {
    //         cout<<v<<" "<<w<<'\n';
    //         cout<<"-----\n";
    //     }
    // return 0;
    while (Q--) {
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        // int cur=y;
        // vector<int> path;
        // while (cur) {
        //     path.push_back(cur);
        //     cur=pre[cur];
        // }
        // for (int i=path.size()-1;i>=0;i--)
        //     cout<<path[i]<<" ";
        cout<<dis[y]<<'\n';
    }
    return 0;
}
