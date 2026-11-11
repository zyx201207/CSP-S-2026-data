#include <bits/stdc++.h>
using namespace std;
int n;
struct s
{
    long long cnt;
    char c;
}a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].cnt >> a[i].c;
    int l = 1, r = n;
    long long ans = 0;
    while (l <= r)
    {
        if (a[l].c == a[r].c)
        {
            if (a[l].cnt < a[r].cnt)
            {
                a[r].cnt -= a[l].cnt;
                ++l;
            }
            else if (a[l].cnt == a[r].cnt)
                ++l, --r;
            else
            {
                a[l].cnt -= a[r].cnt;
                --r;
            }
        }
        else
        {
            if (a[l].cnt < a[r].cnt)
            {
                ans += a[l].cnt;
                a[r].cnt -= a[l].cnt;
                ++l;
            }
            else if (a[l].cnt == a[r].cnt)
            {
                ans += a[l].cnt;
                ++l, --r;
            }
            else
            {
                ans += a[r].cnt;
                a[l].cnt -= a[r].cnt;
                --r;
            }
        }
    }
    cout << ans;
    return 0;
}