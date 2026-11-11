#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 2e6 + 10, maxn2 = 300 + 10;

int c, t, n;
long long k, res;
long long a[maxn], dis[maxn2][maxn2];
bool vis[maxn2][maxn2];

inline long long read(){
    long long x = 0, f = 1;
    char ch = getchar();
    for (;ch < '0' || ch > '9'; ch == '-' && (f = -1), ch = getchar());
    for (;ch >= '0' && ch <= '9'; x = x * 10 + (ch ^ 48), ch = getchar());
    return x * f;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while (t--){
        n = read(), k = read(), res = 0, mem(vis, false);
        for (int i = 1; i <= n; i++){
            a[i] = read();
        }
        if (c <= 6){
            for (int i = 1; i <= n; i++){
                dis[i][i] = 0;
                for (int j = i - 1, p = i; j; j--){
                    for (;a[p] - a[j] > k; p--);
                    dis[j][i] = p == j || dis[p][i] > n ? n + 1 : dis[p][i] + 1;
                }
            }
            for (int i = 1; i <= n; i++){
                for (int j = 1; j < i; j++){
                    for (int k = i + 2; k <= n; k++){
                        if (dis[j][i] == dis[j][i + 1] && dis[i][k] == dis[i + 1][k] && dis[j][k] == dis[j][i] + dis[i][k]){
                            vis[j][k] = true;
                        }
                    }
                }
            }
            for (int i = 1; i <= n; i++){
                for (int j = 1; j < i; j++){
                    for (int k = i + 2; k <= n; k++){
                        res += !vis[j][i] && !vis[i + 1][k] && dis[j][i] == dis[j][i + 1] && dis[j][i] != dis[j][i + 2] && dis[i][k] == dis[i + 1][k] && dis[i][k] != dis[i - 1][k] && dis[j][k] == dis[j][i] + dis[i][k];
                    }
                }
            }
            printf("%lld\n", res);
        }else if (c == 11 || c == 12){
            const long long d = k / (a[2] - a[1]);
            if (d > 1){
                for (int i = 1; i <= n; i++){
                    res += i + (d << 1) - 1 <= n;
                }
            }
            printf("%lld\n", res);
        }else if (c == 13 || c == 14){
            for (int i = 2; i < n; i++){
                const int p1 = lower_bound(a + 1, a + n + 1, a[i + 1] - k) - a, q1 = lower_bound(a + 1, a + n + 1, a[i + 2] - k) - a;
                const int p2 = upper_bound(a + 1, a + n + 1, a[i] + k) - a - 1, q2 = upper_bound(a + 1, a + n + 1, a[i - 1] + k) - a - 1;
                res += (long long)max(0, min(i, q1) - p1) * max(0, p2 - max(i + 1, q2));
            }
            printf("%lld\n", res);
        }
    }

return 0;
}