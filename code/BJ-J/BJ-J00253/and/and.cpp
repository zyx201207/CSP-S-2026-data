#include<bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010];
int f[200010];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        f[i] = 1;
    }
    int ans = 0;
    for (int i=31;i>=0;i--) {
        int cnt = 0;
        for (int j=1;j<=n;j++) {
            if (f[j] == 1 && (a[j]&(1<<i)) != 0) {
                cnt++;
            }
        }
        if (cnt >= m) {
            for (int j=1;j<=n;j++) {
                if ((a[j]&(1<<i)) == 0) {
                    f[j] = 0;
                }
            }
            ans += (1<<i);
        }
    }
    printf("%d\n",ans);
    return 0;
}