#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,w;
};
struct cmp{
    bool operator()(const node a,const node b) {
        return a.w>b.w;
    }
};
priority_queue <node,std::vector <node>,cmp> q;
node add(int x,int y) {
    node p;
    p.v=x;p.w=y;
    return p;
}
int c,n,m,d,qq,w[505],k,u[20005],t[20005],dis[505];
bool vis[505];
vector <node> a[505];
void creat() {
    for (int i=1;i<=k;i++) {
        for (int j=i+1;j<=k;j++) {
            a[u[i]].push_back(add(u[j],t[i]+t[j]));
            a[u[j]].push_back(add(u[i],t[i]+t[j]));
        }
    }
}
int dijkstra(int s,int t) {
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    node x;
    x=add(s,0);
    q.push(x);
    while (!q.empty()) {
        x=q.top();q.pop();
        int u1=x.v,w1=x.w,v1;
        if (vis[u1]) continue;
        vis[u1]=1;
        for (int i=0;i<a[u1].size();i++) {
            v1=a[u1][i].v;
            if (dis[v1]>w1+a[u1][i].w) {
                dis[v1]=w1+a[u1][i].w;
                q.push(add(v1,dis[v1]));
            }
        }
    }
    return dis[t];
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for (int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>k;
        for (int j=1;j<=k;j++) {
            cin>>u[j]>>t[j];
        }
        creat();
    }
    while (qq--) {
        int s,t;
        cin>>s>>t;
        cout<<dijkstra(s,t)+w[s]+w[t]<<endl;
    }

    return 0;
}
