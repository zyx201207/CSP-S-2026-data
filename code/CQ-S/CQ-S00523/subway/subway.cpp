#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cmin(x, y) x=min(x, y)
struct node{int x, v;};
int c, n, m, d, q, w[500005], gr[505][505];
vector<node>g[500005];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=m; i++)cin >> w[i];
    for(int i=1; i<=n; i++){
        int k, x, v;cin >> k;
        while(k--){cin >> x >> v;g[x].push_back({i, v});}
    }memset(gr, 63, sizeof(gr));for(int i=1; i<=n; i++)gr[i][i]=0;
    for(int i=1; i<=m; i++)for(auto j:g[i])for(auto t:g[i])cmin(gr[j.x][t.x], j.v+t.v);
    for(int k=1; k<=n; k++)for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)
        cmin(gr[i][j], gr[i][k]+gr[k][j]);
    while(q--){
        int u, v, ans=LLONG_MAX;cin >> u >> v;
        for(auto i:g[u])for(auto j:g[v])cmin(ans, gr[i.x][j.x]+w[u]+w[v]+i.v+j.v);
        cout << ans << '\n';
    }
    return 0;
}