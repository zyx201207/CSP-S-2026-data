#include <bits/stdc++.h>
using namespace std;
#define N 500005

int n, m, a[N], cnt[N];
vector<int> e[N];

void dfs(int u) {
    for (int v : e[u]) dfs(v), cnt[u] += cnt[v];
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i; i--) {
        if (!cnt[a[i]] && i != n)
            e[a[i + 1]].push_back(a[i]);
        ++cnt[a[i]];
    } dfs(a[n]);
    for (int i = 1; i <= m; i++) printf("%d ", cnt[i]);
    puts("");
    return 0;
}