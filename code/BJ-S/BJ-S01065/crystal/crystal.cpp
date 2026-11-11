#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,ans=1;
long long m,a[500005];
int up(int i)
{
    long long upto=a[i],used=0,cnt=0;
    for (;i>0;i--)
    {
        used+=upto-a[i];
        if (used>m) return cnt;
        cnt++;
    }
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    if (n<=10000)
    {
        for (int i=2;i<=n;i++) ans=max(ans,up(i));
        printf("%d",ans);
        return 0;
    }
    for (int i=1;i<=n;i+=n/1500) ans=max(ans,up(i));
    printf("%d",ans);
}
