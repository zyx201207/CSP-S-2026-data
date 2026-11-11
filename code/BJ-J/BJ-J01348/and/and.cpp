#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, m, a[N], ww = 2147483647, ans = -1;
bool vis[N];
void dfs(int s, int val) {
    if(s == m) {
        ans = max(ans, val);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(s + 1, val & a[i]);
            vis[i] = 0;
        }
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if(n == m) {
        for(int i = 1; i <= m; i++) ww &= a[i];
        printf("%d", ww);
        return 0;
    }
    if(m == 1) {
        sort(a + 1, a + n + 1);
        printf("%d", a[n]);
        return 0;
    }
    if(m == 2) {
        int maxn = -1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j < i; j++)
                maxn = max(maxn, a[i] & a[j]);

        printf("%d", maxn);
        return 0;
    }
    dfs(0, ww);
    printf("%d", ans);
    return 0;
}

