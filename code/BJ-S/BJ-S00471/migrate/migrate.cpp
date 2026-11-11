#include<bits/stdc++.h>
using namespace std;
int c, t, n, dis[10000007][3]; long long d, x[2000006];
vector<pair<int, int> > g[1000007]; priority_queue<pair<long long, int> > q;
struct node{
    int l, r; long long mn, mx;
} tr[8000006];
bool check(long long l1, long long r1, long long l2, long long r2){
    return !(r1 < l2 || r2 < l1);
} void build(int l, int r, int i){
    if(l == r) tr[i] = {l, r, x[l], x[l]}, g[n + i].push_back({l, 1});
    else{
        int mid = (l + r) / 2; tr[i] = {l, r, (long long) 1E18, 0ll};
        build(l, mid, 2 * i), build(mid + 1, r, 2 * i + 1);
        tr[i].mn = min(tr[2 * i].mn, tr[2 * i + 1].mn), tr[i].mx = max(tr[2 * i].mx, tr[2 * i + 1].mx);
        g[i + n].push_back({2 * i + n, 0}), g[i + n].push_back({2 * i + n + 1, 0});
    }
} void add(long long l, long long r, int i, int x){
    if(l <= tr[i].mn && tr[i].mx <= r){
        g[x].push_back({n + i, 0}); return;
    } if(check(l, r, tr[2 * i].mn, tr[2 * i].mx)) add(l, r, 2 * i, x);
    if(check(l, r, tr[2 * i + 1].mn, tr[2 * i + 1].mx)) add(l, r, 2 * i + 1, x);
} void los(int u, int v, int w){
    if(dis[u][0] + w < dis[v][0]) dis[v][2] = dis[v][1], dis[v][1] = dis[v][0], dis[v][0] = dis[u][0] + w;
    else if(dis[u][0] + w < dis[v][1]) dis[v][2] = dis[v][1], dis[v][1] = dis[u][0] + w;
    else dis[v][2] = min(dis[v][2], dis[u][0] + w);
    if(dis[u][1] + w < dis[v][1]) dis[v][2] = dis[v][1], dis[v][1] = dis[u][1] + w;
    else dis[v][2] = min(dis[v][2], dis[u][1] + w);
    dis[v][2] = min(dis[v][2], dis[u][2] + w);
} void bfs(int st){
    for(int i = 1; i <= 5 * n; i++) dis[i][0] = 1E9, dis[i][1] = 1E9, dis[i][2] = 1E9;
    q.push({0, st}); dis[st][0] = 0;// printf("BFSST %d\n", st);
    while(!q.empty()){
        int now = q.top().second; q.pop();// printf("%d %d %d %d %d\n", now, dis[now][0], dis[now][1], dis[now][2], g[now].size());
        for(int i = 0; i < g[now].size(); i++){
            int v = g[now][i].first, w = g[now][i].second;
            bool f = (dis[v][0] == 1E9);
            los(now, v, w);
            if(f) q.push({-dis[v][2] - 1000000 * dis[v][1] - 1000000000000 * dis[v][0], v});
        }
    }
} int main(){
    freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
    scanf("%lld%lld", &c, &t);
    while(t--){
        scanf("%lld%lld", &n, &d);
        for(int i = 1; i <= 5 * n; i++) g[i].clear(), dis[i][0] = 1E9;
        for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
        //printf("READ DONE\n");
        build(1, n, 1); //printf("BUILD DONE\n");
        for(int i = 1; i <= n; i++) add(x[i] + 1, x[i] + d, 1, i);
        //printf("ADD DONE\n");
        //for(int i = 1; i <= 5 * n; i++) for(int j = 0; j < g[i].size(); j++) printf("{%d %d %d}\n", i, g[i][j].first, g[i][j].second);
        long long ans = 0;
        for(int i = 1; i < n; i++){
            bfs(i);
            for(int j = i + 1; j <= n; j++) if(dis[j][0] == dis[j][1] && dis[j][1] != dis[j][2]) ans++;
        } printf("%lld\n", ans);
    } return 0;
}/*
6 4
-3 0 1 2 3 4
*/
