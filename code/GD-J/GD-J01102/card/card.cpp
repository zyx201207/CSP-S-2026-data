#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int n, m, a[N], nxt[N], lst[N], f[N], ans[N];
vector<int> G[N];

void dfs(int x) {
    f[x] = 1;
    for(int v : G[x]) {
        dfs(v);
        f[x] += f[v];
    }
}

signed main() {
    // card
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        if(!nxt[i]) {
            if(i < n) G[i + 1].push_back(i);
        } else {
            G[nxt[i]].push_back(i);
        }
    }
    f[n] = 1, dfs(n);
    for(int i = 1; i <= n; i++) {
        if(!nxt[i]) {
            ans[a[i]] = f[i];
        }
    }
    for(int i = 1; i < m; i++) {
        cout << ans[i] << " ";
    } cout << ans[m];
    return 0;
}