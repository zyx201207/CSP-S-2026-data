#include <bits/stdc++.h>
using namespace std;

struct line{
    long long a, t;
};

struct edge{
    long long v, w;
};

struct node{
    long long id, d;
    bool operator < (const node t) const{
        return d < t.d;
    }
};

long long c, n, m, d, q, w[505], dis[40005];
bool vis[40005];
vector <line> li[505];
vector <edge> g[40005];

long long calc(long long a, long long k){
    return a * 30 + k + 400;
}

void dijkstra(long long s){
    priority_queue <node> pq;
    memset(dis, 0x3f3f3f3f3f3f3f3fll, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    pq.push({s, 0});
    dis[s] = 0;
    vis[s] = true;
    while (!pq.empty()){
        long long u = pq.top().id;
        pq.pop();
        //if (vis[u]) continue ;
        //vis[u] = true;
        for (int i = 0; i < g[u].size(); i++){
            edge e = g[u][i];
            //if (e.v == -1) continue ;
            if (dis[e.v] > dis[u] + e.w){
                dis[e.v] = dis[u] + e.w;
                if (!vis[e.v]){
                     pq.push({e.v, dis[e.v]});
                     vis[e.v] = true;
                }
            }
        }
    }
    return;
}

int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    for (long long i = 0; i <= 400; i++){
        for (long long j = 0; j <= 13000; j++){
            g[i].push_back({-1, 0});
        }
    }
    scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
    for (long long i = 1; i <= m; i++){
        scanf("%lld", &w[i]);
    }
    for (long long i = 1; i <= n; i++){
        long long k;
        scanf("%lld", &k);
        for (long long j = 1; j <= k; j++){
            long long a, t;
            scanf("%lld %lld", &a, &t);
            li[i].push_back({a, t});
            long long pos = calc(a, i);
            g[a][pos] = {pos, t};
            g[pos].push_back({a, t});
        }
        for (int j = 1; j < li[i].size(); j++){
            g[calc(li[i][j].a, i)].push_back({calc(li[i][j - 1].a, i), 0});
            g[calc(li[i][j - 1].a, i)].push_back({calc(li[i][j].a, i), 0});
        }
    }

    for (long long i = 1; i <= q; i++){
        long long x, y;
        scanf("%lld %lld", &x, &y);
        dijkstra(x);
        //for (int i = 1; i <= m; i++){
        //    printf("%d ", dis[i]);
        //}
        printf("%lld\n", dis[y] + w[x] + w[y]);

    }
    //for (int i = 1; i <= m; i++){
    //  for (int j = 0; j < g[i].size(); j++){
     //        if (g[i][j].v == -1) continue ;
     //      printf("%d %d:\n", i, g[i][j].v);
      //     for (int k = 0; k < g[g[i][j].v].size(); k++){
     //       printf("%d ", g[g[i][j].v][k].v);
     //      }
    //        printf("\n");
    //    }
    //   printf("\n");
    //}
    //for (int i = 1; i <= n; i++){
    //  for (int j = 0; j < li[i].size(); j++){
     //       printf("%d ", li[i][j]);
    //    }
    //    printf("\n");
    //}
    return 0;
}
