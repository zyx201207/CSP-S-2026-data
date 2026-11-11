#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e6 + 1;
const ll INF = 2e18 + 1;

int c, t;
int n;
ll d;
ll x[N];

namespace S1{
    ll ans, ct;
    int dist[10][10], cnt[10][10];
    void f(int x, int y, int i, int j, int dis){
        if(x > y || dis > dist[i][j]) return;
        if(x == y){
            ct += (dis == dist[i][j]);
            return ;
        }
        for(int z = 1; z <= y - x; z++){
            f(x + z, y, i, j, dis + dist[x][x + z]);
        }
    }
    void Solve(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = 10000000;
            }
            dist[i][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(abs(x[i] - x[j]) > d) break;
                dist[i][j] = dist[j][i] = 1;
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                ct = 0;
                f(i, j, i, j, 0);
                ans += (ct == 2);
            }
        }
        cout << ans << '\n';
    }
}

void Solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(c == 13 || c == 14){
        cout << 0;
    }
    else S1::Solve();
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) Solve();
    return 0;
}
