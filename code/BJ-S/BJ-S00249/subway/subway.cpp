#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=5e5+10;
struct node {
    int v, w;
};
struct cmp {
    bool operator()(node a, node b) {
        return a.w>b.w;
    }
};
vector<node> g[N*3];
bool vis[N*3];
long long dis[N*3];
int w[N], a[510][N], t[510][N], k[510], pre[510], c, n, m, d, q;
int hall(int x) {
    return x+m;
}
void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({s, 0});
    dis[s]=0;
    for(;!pq.empty();) {
        node x=pq.top();
        pq.pop();
        if(vis[x.v])
            continue;
        vis[x.v]=true;
        for(int i = 0;i<g[x.v].size();i++) {
            if(dis[g[x.v][i].v]>dis[x.v]+g[x.v][i].w)
                dis[g[x.v][i].v]=dis[x.v]+g[x.v][i].w, pq.push({g[x.v][i].v, dis[g[x.v][i].v]});
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1;i<=m&&scanf("%d", w+i);i++);
    for(int i = 1;i<=n&&scanf("%d", k+i);pre[i]=pre[i-1]+k[i], i++)
        for(int j = 1;j<=k[i]&&scanf("%d%d", &a[i][j], &t[i][j]);j++);
    for(int i = 1;i<=m;i++) {
        g[i].pb({hall(i), w[i]});
        g[hall(i)].pb({i, w[i]});
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=k[i];j++) {
            g[hall(a[i][j])].pb({2*m+pre[i-1]+j, t[i][j]});
            g[2*m+pre[i-1]+j].pb({hall(a[i][j]), t[i][j]});
        }
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<k[i];j++) {
            g[2*m+j+pre[i-1]].pb({j+1+2*m+pre[i-1], 0});
            g[j+1+2*m+pre[i-1]].pb({2*m+j+pre[i-1], 0});
        }
    }
    for(int i = 1, x, y;i<=q&&scanf("%d%d", &x, &y);i++) {
        dijkstra(x);
        printf("%lld\n", dis[y]);
    }
    return 0;
}
/*
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
subway is delicious
*/