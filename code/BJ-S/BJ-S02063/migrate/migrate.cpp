#include <bits/stdc++.h>
using namespace std;

int a[2000005];
int d, n, dis_min = 0x7f7f7f7f;
map<int, int> dis_count;
void dfs(int x, int u, int v, int dis = 0) {
    if(a[v] - a[v-1] > d) return;
    if(x == v) {
        dis_min = min(dis, dis_min);
        dis_count[dis]++;
        return;
    }
    int ans = 0;
    for(int i = x + 1; i <= v; i++) {
        if(a[i] - a[x] <= d) {
            dfs(i, u, v, dis+1);
        }
    }
    return;
}

void solve(){
    scanf(" %d %d", &n, &d);
    for(int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
    }
    int ans = 0;
    for(int u = 1; u < n; u++) {
        for(int v = u + 1; v <= n; v++) {
            dis_min = 0x7f7f7f7f;
            dis_count.clear();
            dfs(u, u, v);
            if(dis_count[dis_min] == 2) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while(t--) {
        solve();
    }
    return 0;
}
