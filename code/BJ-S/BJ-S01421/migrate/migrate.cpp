#include<bits/stdc++.h>
using namespace std;
int c, t, n, lst[2000005], cnt[2005][2005];
long long d, x, a[2000005], dis[2005][2005];
bool ch(){
    for(int i = 2;i < n;i++)
        if(a[i + 1] - a[i] != a[2] - a[1])
            return 0;
    return 1;
}
long long sol(){
    long long tmp = d / (a[2] - a[1]);
    return max(0ll, (long long)n - (long long)(tmp * 2ll - 1ll));
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--){
        scanf("%d%lld", &n, &d);
        lst[0] = 1;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            lst[i] = lst[i - 1];
            while(a[i] - a[lst[i]] > d) lst[i]++;
        }
        if(n > 1000 & ch()){
            printf("%lld\n", sol());
            continue;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++){
                dis[i][j] = dis[i][max(i, lst[j])] + 1;
                if(a[j] - a[i] <= d) cnt[i][j] = 1;
                else cnt[i][j] = 0;
                for(int k = i + 1;k < j;k++)
                    if(a[j] - a[k] <= d && dis[i][j] == dis[i][k] + 1)
                        cnt[i][j] = min(3, cnt[i][j] + cnt[i][k]);
                if(cnt[i][j] == 2) ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}
