#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nn = 2e6 + 5;
ll a[nn];
int dp[5005], dp2[5005], minn[nn], sum[5005], maxn[nn];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while(t--){
        int n;
        ll d;
        scanf("%d %lld", &n, &d);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
        }
        if(n <= 3){printf("0\n"); continue;}
        int lst = 1;
        for(int i = 2; i <= n; ++i){
            while(a[i] - d > a[lst]) ++lst;
            minn[i] = lst;
        }
        minn[1] = 1;
        lst = n;
        for(int i = n - 1; i >= 1; --i){
            while(a[i] + d < a[lst]) --lst;
            maxn[i] = lst;
        }
        maxn[n] = n;
        if(c <= 10){
            ll ans = 0;
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j) dp[j] = 1e9, dp2[j] = sum[j] = 0;
                dp[i] = 0; dp2[i] = sum[i] = 1;
                lst = i;
                for(int j = i + 1; j <= n; ++j){
                    int w = max(minn[j], i);
                    if(w == j) break;
                    if(dp[w] != dp[j - 1]) dp[j] = dp[j - 1], dp2[j] = sum[lst] - sum[w - 1];
                    else dp[j] = dp[j - 1] + 1, dp2[j] = sum[j - 1] - sum[w - 1], lst = j - 1;
                    sum[j] = sum[j - 1] + dp2[j];
                    if(dp2[j] == 2) ++ans;
                }
            }
            printf("%lld\n", ans);
            continue;
        }else if(c <= 12){
            ll w = d / (a[2] - a[1]);
            printf("%lld\n", (w <= 1 ? 0 : max(0ll, n - (w * 2 - 1))));
            continue;
        }else if(c <= 14){
            ll ans = 0;
            for(int i = 1; maxn[i] < n; ++i){
                if(maxn[maxn[i] - 1] == n && maxn[maxn[i] - 2] != n) ans++;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}