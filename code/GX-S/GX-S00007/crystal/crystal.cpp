#include<bits/stdc++.h>
using namespace std;
const long long N = 50000000;
long long n, m, sum = 1;
long long a[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(long long i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    /*
    for(long long i = 0; i < n; i++)
    {
        printf("%lld ", a[i]);
    }
    printf("\n");
    */
    for(long long i = 0; i < n; i++)
    {
        //cout << m << "\t" << (a[i + 1] - a[i]) * (sum) << "\n";
        if(m < (a[i + 1] - a[i]) * (sum))
        {
            break;
        }
        m -= (a[i + 1] - a[i]) * (sum);
        sum++;
    }
    printf("%lld", sum);
    return 0;
}
