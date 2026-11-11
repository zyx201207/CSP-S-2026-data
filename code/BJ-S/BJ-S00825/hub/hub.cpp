#include <iostream>
#include <vector>
using namespace std;
#define int long long
vector<int> e[4010];
int dep[4010], f[4010][25];
int dis[4010][4010];
void build(int x, int y) {
    dep[x] = dep[y] + 1;
    f[x][0] = y;
    for(int i : e[x]) {
        if(i == y) continue;
        build(i, x);
    }
}
int n, k, ans = 1e9;
void init() {
    for(int j = 1; (1 << j) <= n; ++j)
        for(int i = 1; i <= n; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1];
}
int lca(int x, int y) {
    if(x == y) return 0;
    if(dep[x] < dep[y]) swap(x, y);
    int res = 0;
    for(int j = 20; j >= 0; --j)
        if(dep[f[x][j]] >= dep[y]) {
            //if(x == 10) cout << endl << f[x][j] << ' ' << j << endl;
            x = f[x][j], res += (1 << j);
        }
    if(x == y) return res;
    for(int j = 20; j >= 0; --j)
        if(f[x][j] != f[y][j]) {
            x = f[x][j], y = f[y][j];
            res += (1 << j);
            res += (1 << j);
        }
    return res + 2;
}
int s[4010];
int check(int x, int cnt, int sz) {
    int flag = 1;
    for(int i = 1; i <= cnt; ++i)
        if(dis[s[i]][x] <= 1) flag = 0;
    if(flag && sz >= 2) return -1;
    return flag;
}
int vis[4010], flag[4010];
void check(int x) {
    vis[x] = 1;
    for(int i : e[x]) {
        if(!flag[i]) continue;
        if(vis[i]) continue;
        check(i);
    }
}
void dfs(int x, int cnt) {
    //if(x == n && cnt == k) cout << 1 << endl;
    if(x > n) return;
    if(cnt > k) return;
    if(cnt == k) {
        for(int i = 1; i <= n; ++i)
            vis[i] = 0, flag[i] = 0;
        for(int i = 1; i <= cnt; ++i)
            flag[s[i]] = 1;
        int sz = 0;
        for(int i = 1; i <= cnt; ++i) {
            if(!vis[s[i]]) {
                check(s[i]);
                sz++;
                if(sz > 2) return;
            }
        }
        int maxn = -1e9;
        for(int i = 1; i <= n; ++i) {
            int minn = 1e9;
            for(int j = 1; j <= cnt; ++j)
                minn = min(minn, dis[i][s[j]]);
            maxn = max(maxn, minn);
        }
        ans = min(ans, maxn);
        /*
        if(maxn == 1) {
            cout << endl << "NO!\n";
            for(int i = 1; i <= cnt; ++i)
                cout << s[i] << ' ';
            cout << endl;
        }
        */
    }
    dfs(x + 1, cnt);
    s[cnt + 1] = x;
    dfs(x + 1, cnt + 1);
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
            e[i].clear();
        for(int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        build(1, 0);
        init();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                dis[i][j] = dis[j][i] = lca(i, j);
                //cout << dis[i][j] << ' ';
            }
            //cout << endl;
        }
        ans = 1e9;
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
