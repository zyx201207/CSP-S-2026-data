#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
#define ll long long 
const int N = 5e5 + 5, M = 505;
const ll inf = 1e18;
vector<int>g[N];
int n, m, d, q;
unordered_map<int, ll>mp[M];
ll dis[M][M], a[N];
signed main(){
    FILE("subway");
    cin.tie(nullptr) -> sync_with_stdio(false);
    int cid; cin >> cid >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int len; cin >> len;
        while(len--){
            int id, x; cin >> id;
            g[id].emplace_back(i);
            cin >> x;
            mp[i][id] = x;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j] = i == j ? 0 : inf;
    for(int i=1;i<=m;i++){
        for(int v1 : g[i]){
            for(int v2 : g[i]){
                if(v1 == v2) continue;
                dis[v2][v1] = dis[v1][v2] = min(dis[v1][v2], mp[v1][i] + mp[v2][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            for(int k=1;k<=n;k++){
                if(k == i || k == j) continue;
                dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        ll res = inf;
        for(int v1 : g[x])
            for(int v2 : g[y])
                res = min(res, dis[v1][v2] + mp[v1][x] + mp[v2][y]);
        res += a[x] + a[y];
        cout << res << '\n';
    }
    return 0;
}