#include<bits/stdc++.h>
#define add(i, j, w) (dis[i][j] = min(dis[i][j], w))
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 505, M = 5e5 + 5;
const ll inf = 1e18;
int c, n, m, d, q, cnt[M];
ll dis[N][N], w[M], x, y, z, ans;
pii S[M][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;++i)scanf("%lld", &w[i]);
    for(int i = 1, k;i <= n;++i){
        scanf("%d", &k);
        for(int j = 1;j <= k;++j){
            int x, t;
            scanf("%d%d", &x, &t);
            S[x][++cnt[x]] = {i, t};
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j)dis[i][j] = inf;
        dis[i][i] = 0;
    }
    for(int i = 1, j, k;i <= m;++i)
        for(j = 1;j <= cnt[i];++j)
            for(k = j + 1;k <= cnt[i];++k){
                x = S[i][j].first, y = S[i][k].first;
                z = S[i][j].second + S[i][k].second;
                add(x, y, z), add(y, x, z);
            }
    for(int k = 1;k <= n;++k)
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
            if(dis[i][k] != inf && dis[k][j] != inf)dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for(int i = 1;i <= q;++i){
        scanf("%lld%lld", &x, &y);
        ans = inf;
        for(int j = 1;j <= cnt[x];++j)
            for(int k = 1;k <= cnt[y];++k) ans = min(ans, dis[S[x][j].first][S[y][k].first] + S[x][j].second + S[y][k].second);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}