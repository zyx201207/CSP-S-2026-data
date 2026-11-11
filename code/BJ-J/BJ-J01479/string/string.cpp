#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
    long long l = 1,r = n;
    long long ans = 0;
    while (l <= r)
    {
        if (c[l] != c[r])
        {
            if (a[l] > a[r])
            {
                ans += a[r];
                a[l] -= a[r];
                a[r] = 0;
                r -= 1;
            }
            else if (a[l] < a[r])
            {
                ans += a[l];
                a[r] -= a[l];
                a[l] = 0;
                l += 1;
            }
            else if (a[l] == a[r])
            {
                ans += a[l];
                a[l] = a[r] = 0;
                l += 1;
                r -= 1;
            }
        }
        else
        {
            if (a[l] > a[r])
            {
                a[l] -= a[r];
                a[r] = 0;
                r -= 1;
            }
            else if (a[l] < a[r])
            {
                a[r] -= a[l];
                a[l] = 0;
                l += 1;
            }
            else if (a[l] == a[r])
            {
                a[l] = a[r] = 0;
                l += 1;
                r -= 1;
            }
        }
    }
    cout << ans;
    return 0;
}
