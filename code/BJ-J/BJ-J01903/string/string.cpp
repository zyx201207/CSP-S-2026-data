#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200010];
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld %c", &a[i], &c[i]);
    }
    ll l = 1, r = n, cnt = 0;
    while(l < r)
    {
        if(c[l] != c[r])
        {
            cnt += min(a[l], a[r]);
            if(a[l] <= a[r])
            {
                a[r] -= a[l];
                l++;
            }
            else
            {
                a[l] -= a[r];
                r--;
            }
        }
        else
        {
            if(a[l] <= a[r])
            {
                a[r] -= a[l];
                l++;
            }
            else
            {
                a[l] -= a[r];
                r--;
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
