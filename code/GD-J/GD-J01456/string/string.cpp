#include <iostream>
#include <cmath>
using namespace std;
struct kmj
{
    long long t = 0;
    char w;
}a[1145140];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, s = 0, k1, k2, ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i].t >> a[i].w;
        s += a[i].t;
    }
    s /= 2;
    k1 = 1;
    k2 = n;
    while (s > 0)
    {
        if (a[k1].w != a[k2].w)
            ans += min(a[k1].t, a[k2].t);
        if (a[k1].t > a[k2].t)
        {
            a[k1].t -= a[k2].t;
            s -= a[k2].t;
            k2--;
        }
        else if (a[k1].t < a[k2].t)
        {
            a[k2].t -= a[k1].t;
            s -= a[k1].t;
            k1++;
        }
        else
        {
            s -= a[k1].t;
            k1++;
            k2--;
        }
    }
    cout << ans;
    return 0;
}
