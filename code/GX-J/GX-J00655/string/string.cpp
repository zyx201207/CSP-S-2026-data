#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long s = 0;
    int n, a[200001];
    char c[200001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int l = 0, ln = 0, r = n - 1, rn = 0;
    while (l < r)
    {
        int tl = a[l] - ln, tr = a[r] - rn;
        if (tl < tr)
        {
            if (c[l] != c[r])
            {
                s += tl;
            }
            l++;
            ln = 0;
            rn += tl;
        }
        else if (tl > tr)
        {
            if (c[l] != c[r])
            {
                s += tr;
            }
            r--;
            rn = 0;
            ln += tr;
        }
        else
        {
            if (c[l] != c[r])
            {
                s += tl;
            }
            l++;
            ln = 0;
            r--;
            rn = 0;
        }
        if (ln == a[l])
        {
            l++;
            ln = 0;
        }
        if (rn == a[r])
        {
            r--;
            rn = 0;
        }
    }
    cout << s;
    return 0;
}
