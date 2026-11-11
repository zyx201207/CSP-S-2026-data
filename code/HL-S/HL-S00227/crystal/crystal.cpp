#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
int main()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort (a+1, a+n+1);

    int l=1, r=n, lnum1=0, rnum1=0, lnum2=0, rnum2=0, maxx=-1;
    int mid=(l+r+1)/2;
    int z=0;
    int x=n;
    while (x--)
    {
        for (int i=1; i < mid; i++)
        {
            lnum1 += a[mid] - a[i];
        }
        for (int i=mid; i <= n; i++)
        {
            rnum1 += a[n] - a[i];
        }
        if (z == 1 && lnum1 > m)
        {
            maxx = max(lnum2, maxx);
        }
        if (z == 2 && rnum1 > m)
        {
            maxx = max(rnum2, maxx);
        }
        lnum2 = lnum1;
        rnum2 = rnum1;
        if (lnum2 < m)
        {
            mid++;
            z = 1;
        }
        else if (rnum2 < m)
        {
            mid--;
            z = 2;
        }
    }
    cout << mid;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
