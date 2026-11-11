#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long s = 0;
    int l = 0,r = n + 1;
    int pl = 0, pr = 0;
    long long sr = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    s /= 2;
    long long t = 0,pot;
    for (int i = 1;i <= n;i++)
    {
        t += a[i];
        if (t >= s)
        {
            pot = a[i] - t + s;
            t = i;
            break;
        }
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    while (sr < s)
    {
        if (pl == 0 && pr == 0)
        {
            if (a[l + 1] >= a[r - 1])
            {
                l++;
                bool x = 0;
                int anr = 0;
                while (anr < a[l])
                {
                    if (1ll * (a[r - 1] + anr) > 1ll * a[l])
                    {
                        x = 1;
                        break;
                    }
                    r--;
                    if (c[l] != c[r])
                    {
                        ans += a[r];
                    }

                    anr += a[r];
                    sr += a[r];
                }
                if (x == 1)
                {
                    r--;
                    if (c[l] != c[r])
                        ans += (a[l] - anr);
                    sr += (a[l] - anr);
                    pr = a[r] - (a[l] - anr);
                }
            }
            else
            {
                r--;
                bool tx = 0;
                int anl = 0;
                while (anl < a[r])
                {
                    if (1ll * (a[l + 1] + anl) > 1ll * a[r])
                    {
                        tx = 1;
                        break;
                    }
                    l++;
                    if (c[l] != c[r])
                    {
                        ans += a[l];
                    }

                    anl += a[l];
                    sr += a[l];
                }
                if (tx == 1)
                {
                    l++;
                    if (c[l] != c[r])
                        ans += (a[r] - anl);
                    sr += (a[r] - anl);
                    pl = a[l] - (a[r] - anl);
                }
            }
        }
        else
        {
            if (pl)
            {
                bool x = 0;
                int anr = 0;
                while (anr < a[l])
                {
                    if (1ll * (a[r - 1] + anr) > 1ll * pl)
                    {
                        x = 1;
                        break;
                    }
                    r--;
                    if (c[l] != c[r])
                        ans += a[r];
                    anr += a[r];
                    sr += a[r];
                }
                if (x == 1)
                {
                    r--;
                    if (c[l] != c[r])
                        ans += (pl - anr);
                    sr += (pl - anr);
                    pr = a[r] - (pl - anr);
                }
                pl = 0;
            }
            else
            {
                bool tx = 0;
                int anl = 0;
                while (anl < pr)
                {
                    if (1ll * (a[l + 1] + anl) > 1ll * pr)
                    {
                        tx = 1;
                        break;
                    }
                    l++;
                    if (c[l] != c[r])
                        ans += a[l];
                    anl += a[l];
                    sr += a[l];
                }
                if (tx == 1)
                {
                    l++;
                    if (c[l] != c[r])
                        ans += (pr - anl);
                    sr += (pr - anl);
                    pl = a[l] - (pr - anl);
                }
                pr = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
