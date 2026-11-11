#include <bits/stdc++.h>
#define int long long
int w[500010];
struct edge {
    int v,w;
};
std::vector<edge> b[500010];
std::queue<edge> q;
int a[510][510];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int c,n,m,d,q,k,u,v;
    std::cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) {
        std::cin>>w[i];
    }
    for(int i = 1;i <= n;i++) {
        std::cin>>k;
        for(int j = 0;j < k;j++) {
            std::cin>>u>>v;
            b[u].push_back({i,v});
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            a[i][j] = 100000000000000000ll;
        }
    }
    for(int i = 1;i <= n;i++) {
        a[i][i] = 0;
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 0;j < b[i].size();j++) {
            for(int h = j+1;h < b[i].size();h++) {
                a[b[i][j].v][b[i][h].v] = std::min(a[b[i][j].v][b[i][h].v],b[i][j].w + b[i][h].w);
                a[b[i][h].v][b[i][j].v] = std::min(a[b[i][h].v][b[i][j].v],b[i][j].w + b[i][h].w);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int k = 1;k <= n;k++) {
            for(int j = 1;j <= n;j++) {
                a[i][j] = std::min(a[i][j],a[i][k] + a[k][j]);
            }
        }
    }
    for(;q--;) {
        std::cin>>u>>v;
        if(u == v) {
            std::cout<<"0\n";
            continue;
        }
        int ans = 100000000000000000ll;
        for(int i = 0;i < b[u].size();i++) {
            for(int j = 0;j < b[v].size();j++) {
                ans = std::min(ans,w[u] + w[v] + b[u][i].w + a[b[u][i].v][b[v][j].v] + b[v][j].w);
            }
        }
        std::cout<<ans<<"\n";
    }
}
