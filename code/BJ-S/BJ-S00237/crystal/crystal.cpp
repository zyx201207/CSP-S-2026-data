#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for (long long i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (long long i=1;i<=n;i++) {
        s[i] = s[i-1]+a[i];
    }
    long long anss = 1;
    for (long long i=1;i<=n;i++) {
        long long l = 1,r = i,ans = i;
        while (l <= r) {
            long long mid = (l+r)/2;
            if (a[i]*(i-mid+1)-(s[i]-s[mid-1]) <= m) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        anss = max(anss,i-ans+1);
    }
    printf("%lld\n",anss);
    return 0;
}