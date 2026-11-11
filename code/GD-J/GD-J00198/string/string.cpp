#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0, len = 0;
pair<long long, char> a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        len += a[i].first;
    }
    long long l = 1, r = len, idl = 1, idr = n;
    while (idl < idr)
    {
        if (a[idl].second == a[idr].second)
        {
            if (a[idl].first < a[idr].first)
            {
                l += a[idl].first;
                r -= a[idl].first;
                a[idr].first -= a[idl].first;
                idl++;
            }
            else if (a[idl].first > a[idr].first)
            {
                r -= a[idr].first;
                l += a[idr].first;
                a[idl].first -= a[idr].first;
                idr--;
            }
            else
            {
                r -= a[idr].first;
                l += a[idr].first;
                idr--;
                idl++;
            }
        }
        else
        {
            if (a[idl].first < a[idr].first)
            {
                l += a[idl].first;
                r -= a[idl].first;
                ans += a[idl].first;
                a[idr].first -= a[idl].first;
                idl++;
            }
            else if (a[idl].first > a[idr].first)
            {
                r -= a[idr].first;
                l += a[idr].first;
                ans += a[idr].first;
                a[idl].first -= a[idr].first;
                idr--;
            }
            else
            {
                r -= a[idr].first;
                l += a[idr].first;
                ans += a[idr].first;
                idr--;
                idl++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}