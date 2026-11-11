#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
const int maxn = 500 + 5;
const int maxm = 5e5 + 5;
const ll inf = 1e18;
int C, n, m, D, q;
ll w[maxm], f[maxn][maxn], ans;
vector <pii> v[maxm];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> D >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(i != j) f[i][j] = inf;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1, x, y, z; i <= n; ++i){
        cin >> x;
        for(int j = 1; j <= x; ++j) cin >> y >> z, v[y].push_back({i, z});
    }
    for(int i = 1; i <= m; ++i)
        for(pii j : v[i])
            for(pii k : v[i]) f[j.first][k.first] = min(f[j.first][k.first], j.second + k.second);
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(f[i][j] > f[i][k] + f[k][j]) f[i][j] = f[i][k] + f[k][j];
    for(int x, y; q; --q){
        ans = inf;
        cin >> x >> y;
        for(pii i : v[x])
            for(pii j : v[y]) ans = min(ans, f[i.first][j.first] + i.second + j.second);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}