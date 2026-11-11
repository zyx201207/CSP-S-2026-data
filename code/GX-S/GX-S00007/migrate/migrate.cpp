#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const long long N = 20000050;
long long t, n, d, sum;
long long aa[N], a[N];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long cccc;
    cin >> cccc;
    cin >> t;
    while(t--)
    {
        sum = 0;
        scanf("%lld %lld", &n, &d);
        for(long long i = 0; i < n; i++)
        {
            scanf("%lld", &aa[i]);
            if(i == 0)
            {
                continue;
            }
            a[i] = aa[i] - aa[i - 1];
        }
        for(long long i = 1; i < n; i++)
        {
            long long l = i;
            long long sm = 0;
            long long rch = 0;
            while(rch + a[l] < d * 2 && l != n)
            {
                rch += a[l];
                l++;
                if(rch > d)
                {
                    if(l - i - 1 == 2)
                    {
                        sum++;
                    }
                    break;
                }
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
