#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long dp[310][310];
long long s[310][310];
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    scanf("%lld%lld",&c,&t);
    for (long long o=1;o<=t;o++) {
        long long n,d;
        scanf("%lld%lld",&n,&d);
        for (long long i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
        }
        if (c <= 10) {
            long long ans = 0;
            for (long long i=1;i<=n;i++) {
                memset(dp,0,sizeof(dp));
                memset(s,0,sizeof(s));
                dp[i][0] = 1;
                s[i][0] = 1;
                for (long long j=i+1;j<=n;j++) {
                    for (long long f=1;f<=n;f++) {
                        dp[j][f] += s[j-1][f-1]-s[(lower_bound(a+1,a+n+1,a[j]-d)-a)-1][f-1];
                        s[j][f] = s[j-1][f]+dp[j][f];
                    }
                    s[j][0] = s[j-1][0];
                    for (long long f=1;f<=n;f++) {
                        if (dp[j][f] != 0) {
                            if (dp[j][f] == 2) {
                                ans++;
                            }
                            break;
                        }
                    }
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}