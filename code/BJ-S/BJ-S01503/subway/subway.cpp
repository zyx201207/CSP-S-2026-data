#include<bits/stdc++.h>
using namespace std;
#define fs first
#define se second
typedef pair<long long, long long> pii;
typedef long long ll;
ll n, m;
int c;
int d, q;
vector<pii> to[500510];
ll dis[510][500510];
ll w[500010];
void inline dj(register int s){
    priority_queue<pii, vector<pii >, greater<pii > > q;
    q.push({0,s});
    dis[s-m][s] = 0;
    while(q.size()){
        register pii now = q.top();
        q.pop();
        register ll d = dis[s-m][now.se];
        register ll p = now.se;
        for(register auto it : to[p]){
            register ll nd = d + it.se;
            if(nd < dis[s-m][it.fs]){
                dis[s-m][it.fs] = nd;
                q.push({nd, it.fs});
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(register int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(register int i = 1; i <= n; i++){
        register int x;
        cin >> x;
        for(register int j = 1; j <= x; j++){
            ll v, w;
            cin >> v >> w;
            to[v].push_back({m+i, w});
            to[m+i].push_back({v,w});
        }
    }
    for(register int i = 1; i <= n; i++){
        for(register int j = 1; j <= n+m; j++){
            dis[i][j] = 1e18+777;
        }
    }
    for(register int i = 1; i <= n; i++){
        dj(m+i);
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+m; j++){
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }*/
    while(q--){
        register int u, v;
        cin >> u >> v;
        ll ans = w[u] + w[v];
        ll minn  = 1e18+7;
        for(register auto it : to[u]){
            minn = min(minn, it.se+dis[it.fs-m][v]);
        }
        ans += minn;
        cout << ans << endl;
    }
    return 0;
}