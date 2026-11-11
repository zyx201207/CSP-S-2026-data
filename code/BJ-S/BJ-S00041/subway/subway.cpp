#include <bits/stdc++.h>
#define M 500011
#define N 511
using namespace std;
typedef long long ll;

int c, n, m, d, q;

struct edge {
    int v, line;
};
vector<edge> node[M];

ll w[M];
int k[N];
vector<int> a[N];
ll t[M][N];

bool vis[M];
ll ans;

void dfs(int x, const int &y, ll sum, int lali) {
    if(x == y) {
        ans = min(ans, sum + t[x][lali]);
        return;
    }
    for(edge i : node[x]) {
        if(vis[i.v] && i.v != y) continue;
        vis[i.v] = true;
        if(lali != i.line)
            dfs(i.v, y, sum + t[x][i.line] + (lali == 0 ? 0 : t[x][lali]), i.line);
        else dfs(i.v, y, sum, i.line);
    }
    return;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    int u; ll v;
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            cin >> u >> v;
            a[i].push_back(u);
            t[u][i] = v;
        }
        for(int j = 1; j <= k[i]; j++) {
            if(j < k[i])
                node[a[i][j - 1]].push_back((edge){a[i][j], i});
            if(j > 1)
                node[a[i][j - 1]].push_back((edge){a[i][j - 2], i});
        }
    }
    int x, y;
    while(q-->0) {
        cin >> x >> y;
        for(int i = 1; i <= m; i++) vis[i] = false;
        ans = LLONG_MAX;
        vis[x] = true;
        dfs(x, y, 0, 0);
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}