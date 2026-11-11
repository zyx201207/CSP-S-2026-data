#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
constexpr int M = 5e5+10, N = 510;
int n, m, d, q;
int w[M];
int k[N];
ll dis[10010][10010];
bool vis[10010][10010];
vector<pair<int, int>> g[M];
void add(int a, int b, int c){g[a].push_back(make_pair(b, c));}
void dijkstra(int st){
    memset(dis[st], 0x3f, sizeof(dis[st]));
    memset(vis[st], 0, sizeof(vis[st]));
    dis[st][st] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, st});
    while(!pq.empty()){
        auto tp = pq.top();pq.pop();
        ll cost = tp.first, u = tp.second;
        if(vis[st][u]) continue;
        vis[st][u] = true;
        for(const auto &it : g[u]){
            int to = it.first, val = it.second;
            if(dis[st][to] > cost+val){
                dis[st][to] = cost+val;
                pq.push({dis[st][to], to});
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int _;
    scanf("%d%d%d%d%d", &_, &n, &m, &d, &q);
    for(int i = 1; i <= m; ++i) scanf("%d", w+i);


        int now = m;
        for(int i = 1; i <= n; ++i){
            scanf("%d", k+i);
            for(int j = 1; j <= k[i]; ++j){
                int a, t;
                scanf("%d%d", &a, &t);
                now += 1;
                add(a, now, t);add(now, a, t);
                if(j > 1) add(now-1, now, 0), add(now, now-1, 0);
            }
        }
        for(int i = 1; i <= m; ++i)
            dijkstra(i);
        for(int i = 1; i <= q; ++i){
            int x, y;scanf("%d%d", &x, &y);
            printf("%lld\n", min(dis[x][y], dis[y][x])+w[x]+w[y]);
        }

    return 0;
}
