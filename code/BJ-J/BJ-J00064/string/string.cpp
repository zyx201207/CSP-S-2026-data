#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int num;
    char c;
}a[200010];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i= 1; i <= n; i++)
    {
        cin >> a[i].num >> a[i].c;
    }
    for (int i = 1, j = n; i <= j; )
    {
        if (a[i].c != a[j].c)
        {
            if (a[i].num >= a[j].num)
            {
                ans += a[j].num;
                a[i].num -= a[j].num;
                j--;
            }
            else
            {
                ans += a[i].num;
                a[j].num -= a[i].num;
                i++;
            }
        }
        else
        {
            if (a[i].num >= a[j].num)
            {
                a[i].num -= a[j].num;
                j--;
            }
            else
            {
                a[j].num -= a[i].num;
                i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
