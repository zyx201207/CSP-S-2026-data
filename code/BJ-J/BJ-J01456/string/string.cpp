#include <bits/stdc++.h>
using namespace std;

long long n, a[200005], x, len, ans, minn;
char c[200005], cc;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x >> cc;
        if (cc != c[len])
        {
            len++;
            c[len] = cc;
            a[len] = x;
        }
        else
        {
            a[len] += x;
        }
    }
    long long l=1, r=len, lpos=a[l], rpos=a[r];
    while (l < r)
    {
        minn = rpos;
        if (lpos < rpos)
        {
            minn = lpos;
        }
        if (c[l] != c[r])
        {
            ans += minn;
        }
        lpos -= minn;
        rpos -= minn;
        if (lpos == 0)
        {
            l++;
            lpos = a[l];
        }
        if (rpos == 0)
        {
            r--;
            rpos = a[r];
        }
    }
    cout << ans << endl;
    return 0;
}