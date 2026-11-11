#include <bits/stdc++.h>
using namespace std;
int n, ans, a[200005], l, x;
char c[200005], a1, b1;
int main()
{
    //freopen ("string.in", r, stdin);
    //freopen ("string.out", w, stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d%s", &x, &c[i]);
        a[i] = l;
        l += a[i];
    }
    for (int i = 1; i <= l / 2; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i > a[j])
            {
                a1 = c[j];
                break;
            }
        }
        for (int j = n; j >= 1; j--)
        {
            if (l - i + 1 > a[j])
            {
                b1 = c[j];
                break;
            }
        }
        if (a1 != b1)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
