#include <bits/stdc++.h>

using namespace std;

long long n, m, a[500010], da[500010], dsum, ans;

inline void calc(int idx)
{
//    printf("calc(%d)\n", idx);
    long long r=1, used=m, k=0;
    for(int i=idx;i>1;--i)
    {
        k+=da[i];
//        printf("da[%d]=%d, used=%d, k=%d\n", i, da[i], used, k);
        if(used>da[i]) used-=k;
        else break;
        r++;
    }
    if(used<0) r--;
//    printf("ans=%d, r=%d\n", ans, r);
    if(ans<r) ans=r;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
//    printf("n=%lld, m=%lld", n, m);
    for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++) da[i]=a[i]-a[i-1], dsum+=i>1?(da[i]>0?da[i]:-da[i]):0;
    if(dsum==0) {printf("%lld\n", n); return 0;}
    if(dsum==n-1) {calc(n); printf("%lld\n",ans); return 0;}
    for(int i=n;i>=1;i--) calc(i);
    printf("%lld\n", ans);
    return 0;
}