#include<bits/stdc++.h>
using namespace std;
struct node {
    int v, w;
};
struct cmp {
    bool operator()(node a, node b) {
        return a.w>b.w;
    }
};
const int N=1e5+10;
bool vis[N], vis2[N];
int n, k, fa[N], ans=INT_MAX, dis[N];
vector<int> g[N];
int find(int x) {
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
bool chk() {
    memset(fa, 0, sizeof(fa));
    for(int i = 1;i<=n;i++)
        fa[i]=i;
    for(int i = 1;i<=n;i++) {
        for(int j = 0, fx, fy;j<g[i].size();j++) {
            fx=find(i), fy=find(g[i][j]);
            if(vis[i]&&vis[g[i][j]]&&fx!=fy)
                fa[fx]=fy;
        }
    }
    set<int> st;
    for(int i = 1;i<=n;i++)
        if(vis[i])
            st.insert(fa[i]);
    return st.size()<=2;
}
void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis2, 0, sizeof(vis2));
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({s, 0});
    dis[s]=0;
    for(;!pq.empty();) {
        node x=pq.top();
        pq.pop();
        if(vis2[x.v])
            continue;
        vis2[x.v]=true;
        for(int i = 0;i<g[x.v].size();i++) {
            if(dis[g[x.v][i]]>dis[x.v]+1)
                dis[g[x.v][i]]=dis[x.v]+1, pq.push({g[x.v][i], dis[g[x.v][i]]});
        }
    }
}
int get() {
    int ans=0;
    for(int i = 1;i<=n;i++) {
        int minn=INT_MAX;
        dijkstra(i);
        for(int j = 1;j<=n;j++) {
            if(vis[j]) {
                minn=min(minn, dis[j]);
            }
        }
        ans=max(ans, minn);
    }
    return ans;
}
void dfs(int step) {
    if(step>n) {
        int cnt=0;
        for(int i = 1;i<=n;i++) {
            if(vis[i])
                cnt++;
        }
        if(cnt==k&&chk()) {
            ans=min(ans, get());
        }
        return ;
    }
    dfs(step+1);
    vis[step]=true;
    dfs(step+1);
    vis[step]=false;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--) {
        memset(vis, 0, sizeof(vis));
        ans=INT_MAX;
        scanf("%d%d", &n, &k);
        for(int i = 1;i<=n;i++)
            g[i].clear();
        for(int i = 1, u, v;i<n&&scanf("%d%d", &u, &v);i++)
            g[u].push_back(v), g[v].push_back(u);
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}