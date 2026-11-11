#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    vector<char> c(n);

    ll len = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %c", &a[i], &c[i]);
        len += a[i];
    }

    if (len <= 2e8)
    {
        string s;
        for (int i = 0; i < n; ++i)
        {
            s += string(a[i], c[i]);
        }
        int l = 0, r = s.size() - 1;
        ll ans = 0;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                ++ans;
            }
            ++l;
            --r;
        }

        cout << ans;
        return 0;
    }

    int l = 0, r = n - 1, cl = 0, cr = 0, sl = 0, sr = 0;
    ll ans = 0;

    while (l < r)
    {
        if (cl)
        {
            if (c[r] != c[l])
            {
                ans += min(a[l] - cl, a[r]);
                // ans += a[r];
            }
            if (a[r] > a[l] - cl)
            {
                cr += a[r] - (a[l] - cl);
                ++l;
                cl = 0;
            }
            else
            {
                cl += a[r];
                --r;
                cr = 0;
            }
        }
        else if (cr)
        {
            if (c[r] != c[l])
            {
                ans += min(a[r] - cr, a[l]);
                // ans += a[l];
            }
            if (a[l] > a[r] - cr)
            {
                cl += a[l] - (a[r] - cr);
                --r;
                cr = 0;
            }
            else
            {
                cr += a[l];
                ++l;
                cl = 0;
            }
        }
        else
        {
            if (c[l] != c[r])
            {
                ans += min(a[r], a[l]);
            }

            if (a[l] < a[r])
            {
                cr += a[l];
                ++l;
                cl = 0;
            }
            else if (a[l] > a[r])
            {
                cl += a[r];
                --r;
                cr = 0;
            }
            else
            {
                cl = cr = 0;
                ++l;
                --r;
            }
        }
    }

    // cout << cl << " " << cr << "\n"
    //      << a[l] << c[l] << " " << a[r] << c[r] << "\n ";

    cout
        << ans;
}
