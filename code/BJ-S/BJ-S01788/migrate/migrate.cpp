#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200005;
int c,T,n;
ll d,a[maxn],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1; i<=n; ++i)
        {
            scanf("%lld",&a[i]);
        }
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        ll der=a[2]-a[1];
        ll q=d/der;
        ll s=d%der;

        if(d<der)
        {
            printf("0\n");
            continue;
        }
        ans=(ll)n-(q*2-1);
        printf("%lld\n",ans);
    }
    return 0;
}
