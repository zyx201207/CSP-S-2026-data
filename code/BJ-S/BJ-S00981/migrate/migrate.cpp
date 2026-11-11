#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
int c, T, n;
long long x[N], d, ans, len[N], dp[N];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--){
        scanf("%d%lld", &n, &d); ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &x[i]);
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                len[j] = INF; dp[j] = 0;
            }
            dp[i] = 1; len[i] = 0;
            for (int j = i; j <= n; j++){
                if (dp[j] == 2) ans++;
                for (int k = j + 1; k <= n && x[k] - x[j] <= d; k++){
                    if (len[j] + 1 < len[k]){ len[k] = len[j] + 1; dp[k] = dp[j]; }
                    else if (len[j] + 1 == len[k]){ dp[k] += dp[j]; }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}