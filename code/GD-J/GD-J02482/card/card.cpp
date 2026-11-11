#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500100], cnt[300100], ans[300100], suf[300100], fa[500100], sz[500100];
vector<int> son[500100];

void dfs(int from) {
    sz[from] = 1;
    for (auto i : son[from]) {
        dfs(i);
        sz[from] += sz[i];
    }
    if (suf[a[from]] == from)
        ans[a[from]] += sz[from];
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i > 0; i--) {
        if (suf[a[i]] > i)
            fa[i] = suf[a[i]], son[suf[a[i]]].push_back(i);
        else
            fa[i] = i + 1, son[i + 1].push_back(i), suf[a[i]] = i;
    }
    dfs(n);
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    puts("");
}