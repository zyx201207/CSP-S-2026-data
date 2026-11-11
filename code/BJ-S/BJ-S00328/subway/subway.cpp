#include<bits/stdc++.h>
// #define YCX
using namespace std;
using LL = long long;
const int N = 505, M = 5e5 + 5, D = 22;
int c, n, m, d, q, w[M], a[M], t[M], cnt[M];
vector<pair<int, int>> g[M * D];
LL dis[M * D];
struct node{
    int x;
    LL dis;
    bool operator<(const node& a) const{
        return dis > a.dis;
    }
};
priority_queue<node> Q;
LL bfs(int s, int t){
    for(int i = 1; i <= m; ++i)
        for(int j = 0; j <= cnt[i]; ++j)
            dis[i + j * m] = 1e18;
    Q.push({s, 0});
    dis[s] = 0;
    while(!Q.empty()){
        int x = Q.top().x, nd = Q.top().dis;
        Q.pop();
        if(nd > dis[x]) continue;
        #ifdef YCX
        if(x == 6) printf("%d %lld\n", x, dis[x]);
        #endif
        for(auto e : g[x]){
            int y = e.first, z = e.second;
            #ifdef YCX
                if(y == 11) printf("%lld %lld %d\n", dis[y], dis[x], z);
            #endif
            if(dis[y] > dis[x] + z){
                dis[y] = dis[x] + z;
                #ifdef YCX
                    if(y == 11) printf("%d\n", y);
                #endif
                Q.push({y, dis[y]});
            }
        }
    }
    return dis[t];
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; ++i){
        scanf("%d", &w[i]);
        g[i].push_back({i + m, w[i]});
        g[i + m].push_back({i, w[i]});
            #ifdef YCX
                printf("%d %d %d\n", i, i + m, w[i]);
            #endif
        cnt[i] += 2;
    }
    for(int i = 1; i <= n; ++i){
        int k;
        scanf("%d", &k);
        for(int j = 1; j <= k; ++j){
            scanf("%d%d", &a[j], &t[j]);
            cnt[a[j]]++;
            #ifdef YCX
                printf("%d %d %d\n", a[j] + m, a[j] + m * (cnt[a[j]] - 1), t[j]);
            #endif
            g[a[j] + m].push_back({a[j] + m * (cnt[a[j]] - 1), t[j]});
            g[a[j] + m * (cnt[a[j]] - 1)].push_back({a[j] + m, t[j]});
        }
        for(int j = 2; j <= k; ++j){
            #ifdef YCX
                printf("%d %d %d\n", a[j-1] + m * (cnt[a[j-1]] - 1), a[j] + m * (cnt[a[j]] - 1), 0);
            #endif
            g[a[j-1] + m * (cnt[a[j-1]] - 1)].push_back({a[j] + m * (cnt[a[j]] - 1), 0});
        }
    }
#ifdef YCX
    for(int i = 1; i <= m; ++i)
        printf("%d ", cnt[i]);
    puts("");
#endif
    while(q--){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", bfs(x, y));
    }
    return 0;
}