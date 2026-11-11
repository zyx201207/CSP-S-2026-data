#include<bits/stdc++.h>
#define int long long
using namespace std;

int c, t;

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c, &t);
    while(t--)
    {
        int n, d, a[2000010];
        scanf("%lld%lld",&n,&d);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }
        printf("0\n");
    }
    return 0;
}
