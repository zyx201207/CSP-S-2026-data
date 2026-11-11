#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> II;
typedef pair<ll, int> LI;
const int maxn = 509, maxm = 5e5 + 10, maxd = 29, maxq = 1e5 + 10;
int c, n, m, d, q;
int w[maxm], k[maxn];
vector<II> edge[maxm + maxn];
const ll INF = 1e18 + 10;
ll dis[maxm + maxn];
bool vis[maxm + maxn];
ll djs(int x, int y){
    for(int i = 1; i <= m + n; i++) dis[i] = INF, vis[i] = false;
    priority_queue<LI, vector<LI>, greater<LI> > q;
    dis[x] = 0;
    q.push({0, x});
    while(!q.empty()){
        const ll used = q.top().first;
        const int pos = q.top().second;
        q.pop();
        if(pos == y) break;
        if(vis[pos]) continue;
        vis[pos] = true;
        for(II x: edge[pos]){
            const int we = x.first;
            const int to = x.second;
            if(dis[to] > dis[pos] + we){
                dis[to] = dis[pos] + we;
                q.push({dis[to], to});
            }
        }
    }
    return dis[y];
}
int main(){
    goto start;
    end:
    fclose(stdin);
    fclose(stdout);
    return 0;
    start:
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++){
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
        for(int j = 1, a, t; j <= k[i]; j++){
            scanf("%d %d", &a, &t);
            edge[a].push_back({t, m + i});
            edge[m + i].push_back({t, a});
        }
    }
    for(int i = 1, x, y; i <= q; i++){
        scanf("%d %d", &x, &y);
        printf("%lld\n", djs(x, y) + w[x] + w[y]);
    }
    goto end;
}
