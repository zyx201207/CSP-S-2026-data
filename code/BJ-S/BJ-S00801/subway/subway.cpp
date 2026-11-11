#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x = 1,s = 0;
    char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') x = -1;
    for (;isdigit(c);c = getchar()) s = s * 10 + c - '0';
    return x * s;
}
#define pii pair<int,ll>
#define fi first
#define se second
const int M = 5e5 + 5,N = 505;
int n,m,c,d,q;
ll w[M],dis[N][N];
vector<pii> g[N],h[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // 输入
    c = read(),n = read(),m = read(),d = read(),q = read();
    for (int i = 1;i <= m;++i) w[i] = read();
    for (int i = 1;i <= n;++i){
        int k;
        k = read();
        while (k--){
            int v = read(),t = read();
            g[i].push_back({v,t});
            h[v].push_back({i,t});
        }
    }

    // fl 初始化
    memset(dis,0x3f,sizeof(dis));
    for (int i = 1;i <= n;++i){
        dis[i][i] = 0;
        for (int j = 0;j < g[i].size();++j){
            int v = g[i][j].fi;
            for (int k = 0;k < h[v].size();++k){
                int t = h[v][k].fi;
                dis[t][i] = dis[i][t] = min(dis[i][t],g[i][j].se + h[v][k].se);
            }
        }
    }

    // 求最段路
    for (int k = 1;k <= n;++k)
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= n;++j)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);

    // 输出
    while (q--){
        int x = read(),y = read();
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0;i < h[x].size();++i)
            for (int j = 0;j < h[y].size();++j)
                ans = min(ans,dis[h[x][i].fi][h[y][j].fi] + h[x][i].se + h[y][j].se);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
