#include<bits/stdc++.h>
#define ll long long
#define pil pair<int, ll>
#define pli pair<ll, int>
using namespace std;
const int N = 5010, M = 500100;
ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x <= 9){
        putchar(x + '0');
        return;
    }
    write(x / 10);
    putchar(x % 10 + '0');
}

int c, n, m, d, w[M];
ll dist[N][N];
vector<pil> edges[N], g[M];

void dijkstra(int s){
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, s});
    dist[s][s] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        for (auto _ : edges[u]){
            int v = _.first;
            ll w = _.second;
            if(dist[s][v] > dist[s][u] + w){
                dist[s][v] = dist[s][u] + w;
                q.push({dist[s][v], v});
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read();
    int Q = read();
    for (int i = 1; i <= m; i++)
        w[i] = read();
    for (int i = 1; i <= n; i++){
        int k = read();
        for (int j = 1; j <= k; j++){
            int a = read(), t = read();
            g[a].push_back({i, t});
        }
    }
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++){
        for (auto _1 : g[i]){
            for (auto _2 : g[i]){
                if(_1 == _2)
                    continue;
                int u = _1.first, v = _2.first;
                ll w = _1.second + _2.second;
                dist[u][v] = min(dist[u][v], w);
                dist[v][u] = min(dist[v][u], w);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(dist[i][j] != 0x3f3f3f3f3f3f3f3f){
                edges[i].push_back({j, dist[i][j]});
                edges[j].push_back({i, dist[i][j]});
            }
        }
    }
    memset(dist, 0x3f, sizeof dist);
    for (int s = 1; s <= n; s++)
        dijkstra(s);
    while(Q--){
        int s = read(), t = read();
        ll mn = LONG_LONG_MAX;
        for (auto _1 : g[s]){
            int u = _1.first;
            ll t1 = _1.second;
            for (auto _2 : g[t]){
                int v = _2.first;
                ll t2 = _2.second;
                mn = min(mn, w[s] + w[t] + t1 + t2 + dist[u][v]);
            }
        }
        write(mn);
        puts("");
    }
}