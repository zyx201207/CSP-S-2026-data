#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;

int n, c, T, k;
vector<int> g[N];


int di[N], dis2[N], mxdis, mxdis2, A, B, ban1, ban2;

void Dfs1(int u, int f) {
    di[u] = di[f] + 1;
    if(di[u] > mxdis) A = u, mxdis = di[u];
    for(int v : g[u]) {
        if(v == f || v == ban1 || v == ban2) continue;
        Dfs1(v, u);
    }
}

void Dfs2(int u, int f) {
    dis2[u] = dis2[f] + 1;
    if(dis2[u] > mxdis2) mxdis2 = dis2[u], B = u;
    for(int v : g[u]) {
        if(v == f || v == ban1 || v == ban2) continue;
        Dfs2(v, u);
    }
}

int diameter() {
    int ans = 0x7f7f7f7f;
    for(int u = 1; u <= n; u++) {
        for(int v : g[u]) {
            ban1 = u, ban2 = v;
            int a1 = 0, a2 = 0;
            mxdis = mxdis2 = 0;
            Dfs1(u, v);
            Dfs2(A, 0);
            a1 = mxdis2;


            mxdis = mxdis2 = 0;
            Dfs1(v, u);
            Dfs2(A, 0);
            a2 = mxdis2;
            ans = min(ans, max(a1 / 2, a2 / 2));
        }
    }
    return ans;

}


void solveA() {
    int m = n / 2;
    if(k >= m) {
        cout << 1 << endl;
        return;
    }
    cout << (m - k + 1) / 4 + 1 << endl;

}

bool chosen[12], vis[12];
int dis[12][12], x;

void dfs(int u, int f) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(chosen[v] && v != f) dfs(v, u);
    }
}

void dfs2(int u, int f) {
    dis[x][u] = dis[x][f] + 1;
    for(int v : g[u]) {
        if(v != f) dfs2(v, u);
    }
}

void brute() {
    int ans = 0x7f7f7f7f;

    for(x = 1; x <= n; x++) dis[x][0] = -1, dfs2(x, 0);
    /*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    */
    for(int S = 0; S < (1 << n); S++) {
        if(__builtin_popcount(S) != k) continue;
        for(int k = 0; k < n; k++) chosen[k + 1] = (S >> k) & 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++) vis[i] = 0;
        for(int i = 1; i <= n; i++) if(chosen[i] && !vis[i]) dfs(i, 0), cnt++;
        if(cnt > 2) continue;
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            if(chosen[i]) continue;
            int tmp = 0x7f7f7f7f;

            for(int j = 1; j <= n; j++) {
                if(chosen[j]) tmp = min(tmp, dis[i][j]);
            }
            mx = max(mx, tmp);
        }
        ans = min(ans, mx);

        /*


        if(ans == 1) {
            cout << cnt << endl;
            for(int i = 1; i <= n; i++) if(chosen[i]) cout << i << " ";
            cout << endl;
        }
        */


    }

    cout << ans << endl;
}

void solve() {
    // Property: There's one way to put two consecutive blocks into different sub-trees, using root changing.
    // So we just change root for once and turn it to a single-block sub-problem.
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();

    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(k == 2) cout << diameter() << endl;

    if(c == 13 || c == 14) {
        solveA();
        return;
    }

    if(c == 1 || c == 2 || c == 3) {
        brute();
        return;
    }

    cout << (n - k) / 4 << endl;

}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> T;
    while(T--) solve();
    return 0;
}
