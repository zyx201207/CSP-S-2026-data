#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5+5;
const long long inf = 1e18;
int c, n, m, d, q;
long long f[N][N];
int w[M];
vector<pair<int, int> > st[M];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        while(k--){
            int x, y; cin >> x >> y;
            st[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) f[i][j] = inf;
    for(int i = 1; i <= m; i++){
        int len = st[i].size();
        for(int j = 0; j < len; j++) for(int k = j+1; k < len; k++){
            int u = st[i][j].first, v = st[i][k].first;
            f[u][v] = min(f[u][v], 1ll*st[i][j].second+st[i][k].second);
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = min(f[j][i], f[i][j]);
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        int lx = st[x].size(), ly = st[y].size();
        long long ans = inf;
        for(int i = 0; i < lx; i++) for(int j = 0; j < ly; j++){
            ans = min(ans, f[st[x][i].first][st[y][j].first]+st[x][i].second+st[y][j].second);
        }
        cout << ans+w[x]+w[y] << '\n';
    }
    return 0;
}