#include <bits/stdc++.h>
using namespace std;

int n, m, a[500000], s[300000], t[500000], i, j, x;

void dfs(int pos) {
    auto it = find(t, t+x, a[pos]);
    
    if(it != t+x) {
        fill(t, t+x, 0);
        x=1;
    }
    t[x] = a[pos];
    ++x;

    if(pos==n) {
        for(j=1; j<=x; ++j) {
            ++s[t[j]];
        }
        return;
    }
    dfs(pos+1);
}


int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d%d", &n, &m);
    fill(s, s+m, 0);
    for(i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
    }
    for(i=1; i<=n; ++i) {
        fill(t, t+n, 0);
        x=1;
        dfs(i);
    }
    for(i=1; i<=m; ++i) {
        printf("%d ", s[i]);
    }
    return 0;
}