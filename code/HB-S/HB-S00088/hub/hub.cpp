#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int c , T , n , k , ans = 0x3f3f3f3f;
bool book1[N] , book2[N] , book3[N];
vector < int > e[N];
int dp[N] , f[N][25];

void dfs3 (int u , int fa) {
    dp[u] = dp[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i <= 20; i ++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v : e[u])
        if (v != fa)
            dfs3(v , u);
    return ;
}

int lca (int u , int v) {
    if (dp[u] < dp[v])
        swap(u , v);
    for (int i = 20; i >= 0; i --)
        if (dp[f[u][i]] >= dp[v])
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i --)
        if (f[u][i] != f[v][i])
            u = f[u][i] , v = f[v][i];
    return f[u][0];
}

int dist (int u , int v) {
    return dp[u] + dp[v] - 2 * dp[lca(u , v)];
}

void dfs2 (int u , int fa) {
    book2[u] = 1;
    for (int v : e[u])
        if (v != fa && book1[v] && !book2[v])
            dfs2(v , u);
    return ;
}

inline bool checkscc () {
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        if (book1[i] && !book2[i]) {
            sum ++;
            dfs2(i , 0);
        }
    return sum <= 2;
}

inline int bfs (int st) {
    int mn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++)
        if (book1[i])
            mn = min(mn , dist(i , st));
    return mn;
}

void dfs (int st , int cnt) {
    if (cnt == k) {
        memset(book2 , 0 , sizeof book2);
        if (checkscc()) {
            int mx = 0;
            for (int i = 1; i <= n; i ++)
				if (!book1[i])
					mx = max(mx , bfs(i));
            ans = min(ans , mx);
        }
        return ;
    }
    if (st > n)
        return ;
    dfs(st + 1 , cnt);
    book1[st] = 1;
    dfs(st + 1 , cnt + 1);
    book1[st] = 0;
    return ;
}

int main () {
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> T;
    while (T --) {
        cin >> n >> k;
        ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i ++)
            e[i].clear();
        for (int i = 1; i < n; i ++) {
            int u , v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs3(1 , 0);
        dfs(1 , 0);
        cout << ans << "\n";
    }
    return 0;
}

/*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
