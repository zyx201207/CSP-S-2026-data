#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MAXM = 5e5 + 10;
const ll MAXN = 550;
const ll MAXD = 25;
const ll inf = 1e18;

ll C, n, m, d, Q;
ll w[MAXM];
ll k[MAXN];
vector<ll> a[MAXN], t[MAXN];
vector<pll> e[MAXM];

ll dis[MAXN][MAXN];
void dijkstra(ll);

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%lld%lld%lld%lld%lld", &C, &n, &m, &d, &Q);
    for(ll i = 1; i <= m; i++) scanf("%lld", w + i);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", k + i);
        a[i].push_back(-1);
        t[i].push_back(-1);
        for(ll j = 1; j <= k[i]; j++){
            ll x, y;
            scanf("%lld%lld", &x, &y);
            e[x].push_back({i, j});
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }

    // printf("%lld\n", n);
    for(ll i = 1; i <= n; i++) dijkstra(i);
    // for(ll i = 1; i <= n; i++)
    //     for(ll j = i + 1; j <= n; j++)
    //         printf("%lld %lld %lld\n", i, j, dis[i][j]);

    while(Q--){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ll tmp = w[x] + w[y];

        ll ans = inf;
        for(pll i : e[x]){
            for(pll j : e[y]){
                ans = min(ans, t[i.first][i.second] + t[j.first][j.second] + dis[i.first][j.first]);
            }
        }
        printf("%lld\n", ans + tmp);
    }
    return 0;
}

struct node{
    ll u, d;
    bool operator < (const node& tmp) const{
        return d > tmp.d;
    }
};

priority_queue<node> pq;
void dijkstra(ll x){
    // printf("dij %lld\n", x);
    fill(dis[x] + 1, dis[x] + n + 1, inf);
    while(!pq.empty()) pq.pop();
    dis[x][x] = 0;
    pq.push({x, 0});

    while(!pq.empty()){
        node top = pq.top(); pq.pop();
        ll u = top.u, d = top.d;
        if(d != dis[x][u]) continue;
        // printf("\tud%lld %lld\n", u, d);

        for(ll i = 1; i <= k[u]; i++){
            ll tnode = a[u][i];
            // printf("\t\t%lld %lld\n", i, tnode);
            for(pll j : e[tnode]) if(j.first != u){
                ll tj = j.first;
                // printf("\t\t\t%lld\n", tj);
                ll tmp = t[u][i] + t[tj][j.second];
                // printf("\t\t\t%lld %lld tmp: %lld\n", t[u][tnode], t[tj][j.second], tmp);
                if(d + tmp < dis[x][tj]){
                    dis[x][tj] = d + tmp;
                    pq.push({tj, dis[x][tj]});
                }
            }
        }
    }
}