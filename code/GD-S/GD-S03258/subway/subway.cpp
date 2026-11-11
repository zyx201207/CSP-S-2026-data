#include<bits/stdc++.h>
typedef long long ll;


const ll INF = 0x3f3f3f3f'3f3f3f3f;
const int MAXN = 550;
const int MAXM = 5e5 + 10;
struct sta{
    ll x, t;
}t[MAXM][50];
ll r, n, m, d, q;
ll w[MAXM];
ll dis[MAXN][MAXN];
std::vector<ll> sub[MAXN];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%lld %lld %lld %lld %lld", &r, &n, &m, &d, &q);
    for(int i = 1;i <= m;i++) scanf("%lld", w + i);
    for(int i = 1;i <= n;i++){
        ll k;
        scanf("%lld", &k);
        for(int j = 1;j <= k;j++){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            sub[i].push_back(x);
            t[x][t[x][0].t + 1] = {i, y}, t[x][0].t++;
        }
    }
    
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1;i <= n;i++) dis[i][i] = 0ll;
    for(int i = 1;i <= m;i++){
    for(int a = 1;a <= t[i][0].t;a++){
    for(int b = 1;b <= t[i][0].t;b++){
        if(a == b) continue;
        dis[t[i][a].x][t[i][b].x] = std::min(t[i][a].t + t[i][b].t, dis[t[i][a].x][t[i][b].x]);
    }}}

    for(int k = 1;k <= n;k++){
    for(int a = 1;a <= n;a++){
    for(int b = 1;b <= n;b++){
        dis[a][b] = std::min(dis[a][b], dis[a][k] + dis[k][b]);
    }}}

    while(q--){
        ll a, b, ans = INF;
        scanf("%lld %lld", &a, &b);
        for(int i = 1;i <= t[a][0].t;i++){
        for(int j = 1;j <= t[b][0].t;j++){
            ans = std::min(ans, dis[t[a][i].x][t[b][j].x] + t[a][i].t + t[b][j].t);
        }}
        printf("%lld\n", (ans + w[a] + w[b]));
    }

    return 0;
}