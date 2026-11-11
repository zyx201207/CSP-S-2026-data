#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[500010],b[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(int i=2,j=1;i<=n;i++)
    {
        while(j<i&&1ll*(i-j)*a[i]-(b[i-1]-b[j-1])>m)j++;
        ans=max(ans,1ll*i-j+1);
    }
    printf("%lld\n",ans);
    return 0;
}
