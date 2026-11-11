#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d %c",&a[i],&c[i]);
    }
    long long ans = 0;
    int l = 1,r = n;
    int pl = 1,pr = 1;
    int le = a[l],re = a[r];
    while (l < r) {
        if (le < re) {
            if (c[l] != c[r]) {
                ans += 1ll*le;
            }
            l++;
            re -= le;
            le = a[l];
        } else if (le > re) {
            if (c[l] != c[r]) {
                ans += 1ll*re;
            }
            r--;
            le -= re;
            re = a[r];
        } else {
            if (c[l] != c[r]) {
                ans += 1ll*re;
            }
            l++;
            r--;
            le = a[l];
            re = a[r];
        }
    }
    printf("%lld\n",ans);
    return 0;
}