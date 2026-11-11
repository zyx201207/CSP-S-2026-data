#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500010];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n==1)
    {
        printf("1");
        return 0;
    }
    else{
        int x=1;
        int grshp=a[2]-a[1];
        while(m-x*grshp>=0)
        {
            m-=x*grshp;
            x++;
        }
        printf("%lld",x);
        return 0;
    }
    return 0;
}
