#include <bits/stdc++.h>
using namespace std;
int n, l, r;
long long ans;
char b;
struct s
{
    long long x;
    char c;
} a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].c;
    }
    l = 1, r = n, b = a[1].c;
    while (l <= r)
    {
        if (a[r].x > a[l].x)
        {
            if (a[r].c == a[l].c)
            {
                a[r].x -= a[l].x;
                l++;
            }
            else
            {
                a[r].x -= a[l].x;
                l++;
                ans += a[l].x;
            }
        }
        else
        {
            if (a[r].c == a[l].c)
            {
                a[l].x -= a[r].x;
                r--;
            }
            else
            {
                a[l].x -= a[r].x;
                r--;
                ans += a[r].x;
            }
        }
    }
    cout << ans;
    return 0;
}
