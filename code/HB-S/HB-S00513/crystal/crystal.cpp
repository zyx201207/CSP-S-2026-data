#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],ans=-1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    long long l=1;
    for(int i=1;i<=n;i++)
        {
        while(l<i&&(i-l+1ll)*a[i]-(s[i]-s[l-1])>m)l++;
        ans=max(ans,i-l+1);
        }
    printf("%lld\n",ans);
    return 0;
}
