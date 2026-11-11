/*
18:21写完，发呆了很长时间，条了很长时间
*/

#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 2000010;
int n;
ll k;
ll a[N];
int c, t;
int ans[15];
int cnt;
int f[15];
int g[N];

void dfs (int now, int _) {
    if (f[now - 1] == _) {
        ans[now - 1] ++;
        return ;
    } for (int i = f[now - 1] + 1; i <= _; i ++) {
        if (a[i] - a[f[now - 1]] > k) break;
        f[now] = i;
        dfs (now + 1, _);   
    }
}

int main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t --) {
    
    cnt = 0;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", a + i);
    } if (c == 11 || c == 12) {
        ll _ = a[2] - a[1];
        ll ans = n - (k/_)*2 + 1;
        if (k < 2*_ || ans < 0) printf("0\n");
        else printf("%lld\n", ans);
        continue;
    } if (c == 3 || c == 4 || c == 5 || c == 6) { 
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                int now = 1, pre = i; g[1] = i; bool f = true;
                for (int o = i + 1; o < j; o ++) {
                    if (a[o + 1] - a[pre] > k) {
                        if (a[o] - a[pre] > k) {
                            f = false;
                            break;
                        } else {
                            g[++ now] = o;
                            pre = o;
                        }
                    }
                } if (f == false || a[j] - a[g[now]] > k) continue;
                // if (i == 1 && j == 5) {
                //     for (int i = 1; i <= now; i ++) printf("%d ", g[i]);
                //     printf("(%d %d)", a[5], a[4]);
                // }
                g[now + 1] = j;
                int ff = 0;
                for (int o = 2; o <= now; o ++) {
                    if (g[o] - g[o - 1] > 1) {
                        if (a[g[o] - 1] - a[g[o - 1]] <= k && a[g[o + 1]] - a[g[o] - 1] <= k && (a[g[o] - 2] - a[g[o - 1]] > k || a[g[o + 1]] - a[g[o] - 2] > k)) ff ++;
                    }
                } if (ff == 1) {
                    ans ++;
                    // printf("[%d %d]\n", i, j);
                }
            }
        }
        printf("%d\n", ans);
        continue;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            for (int k = 1; k <= j - i + 1; k ++) ans[k] = 0; 
            f[0] = i;
            dfs (1, j);
            for (int k = 1; k <= j - i + 1; k ++) {
                // printf("[%d %d %d %d]\n", i, j, k, ans[k]);
                if (ans[k] == 2) {
                    cnt ++;
                } if (ans[k] > 0) break;
            }
        }
    }
    printf("%d\n", cnt);

    }
    return 0;
}