#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, d, q, w[N], k, a, t;
int dis[503][503];
struct qwq{
    int id, t;
};
vector<qwq> v[N];
void init(){
    cin >> t >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        cin >> k;
        while (k--){
            cin >> a >> t;
            v[a].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1;i <= m;i++){
        k = v[i].size();
        for (int x = 0;x < k;x++){
            for (int y = 0;y < k;y++){
                if (x == y) continue;
                dis[v[i][x].id][v[i][y].id] = min(dis[v[i][x].id][v[i][y].id], v[i][x].t + v[i][y].t);
            }
        }
    }
}
void floyd(){
    for (int i = 1;i <= n;i++) dis[i][i] = 0;
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init(); floyd();
    int x, y, ans;
    while (q--){
        cin >> x >> y;
        ans = 1e18;
        for (auto i : v[x])
            for (auto j : v[y])
                ans = min(ans, i.t + j.t + dis[i.id][j.id]);
        cout << (ans + w[x] + w[y]) << '\n';
    }
}
