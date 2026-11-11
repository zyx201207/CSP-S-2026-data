#include <bits/stdc++.h>
using namespace std ;

int c , t;
int n , ans;
long long d , x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t --)
    {
        ans = 0;
        scanf("%d%lld",&n,&d);
        for(int i = 1 ; i <= n ; i ++)
        {
            scanf("%lld",&x[i]);
        }
        if(c == 11 || c == 12 || c == 0)//11 12
        {
            long long cha = x[2] - x[1];
            long long f = d/cha;
            if(f > 2)//can fly
            {
                for(long long p = f + 1 ; p <= 2 * f - 1 ; p ++)
                {
                    for(long long i = 0 ; p + i * f <= n ;i ++)
                    {
                        ans += n - (p + i * f) + 1;
                    }
                }
            }
            cout << ans;
        }
    }
    return 0;
}