#include <bits/stdc++.h>
using namespace std;

long long c, t, n, m, u, v, cnt = 0, ts = 0, sv1[10005], sv2[10005], ans = 0, minn = 2e18, a[15];

void dfs(long long now, long long cnt){
    if (now == v){
        if (minn > cnt){
            minn = cnt;
            ans = 1;
        }
        else if (minn == cnt){
            ans++;
        }
        return ;
    }
    //dfs(now + 1, cnt + 1);
    for (long long i = now + 1; i <= v; i++){
        if (a[i] - a[now] > m) continue ;
        dfs(i, cnt + 1);
    }
    return ;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &c, &t);
    while (t--){
            cnt = 0;
            ts=0;
        scanf("%lld %lld", &n, &m);
        for (long long i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        for (long long i = 1; i <= n; i++){
            for (long long j = i + 1; j <= n; j++){
                u = i, v = j;
                minn = 2e18;
                ans = 0;
                dfs(i, 0);
                if (ans == 2){
                        cnt++;
                                        sv1[++ts] = u;
                sv2[ts] = v;
                }

            }
        }
        printf("%lld\n", cnt);
        for (int i = 1; i <= ts; i++){
            printf("[%d %d] ", sv1[i], sv2[i]);
        }
    }
    return 0;
}
