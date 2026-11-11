#include<bits/stdc++.h>
using namespace std;

int n, m, maxn, v[200005];
int a[200005], sum[200005];

int f(int n) {
    long long res = (1 << 31) - 1;
    for (int i = 1; i <= n; i++) {
        if (v[i] != 0)
            res &= a[i];
    }
    return res;
}

void dfs(int x) {
    if (x == 0) {
        maxn = max(maxn, f(n));
        return ;
    }
    for (int i = 1; i <= n; i++)
        if (!v[i]) {
            v[i] = 1;
            dfs(x - 1);
            v[i] = 0;
        }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(m);
    printf("%d", maxn);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
