#include <bits/stdc++.h>
using namespace std;
int a[(int)2e5+10];
char c[(int)2e5+10];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
        getchar();
        scanf("%c",&c[i]);
    }
    int l = 1,r = n;
    while (r - l > 0) {
        if (c[l] == c[r]) {
            if (a[l] > a[r]) a[l] -= a[r],r--;
            else if (a[l] < a[r]) a[r] -= a[l],l++;
            else l++,r--;
        } else {
            if (a[l] > a[r]) {
                ans += a[r];
                a[l] -= a[r],r--;
            } else if (a[l] < a[r]) {
                ans += a[l];
                a[r] -= a[l],l++;
            } else {
                ans += a[l];
                l++,r--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
