#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cin >> c[i];
    }
    int p = n;
    for (int i = 1;i <= n;i++)
    {
        while (a[i] >= a[p])
        {
            if (c[i] != c[p]) ans += a[p];
            a[i] -= a[p];
            a[p] = 0;
            p--;
        }
        if (c[i] != c[p]) ans += a[i];
        a[p] -= a[i];
        a[i] = 0;
    }
    cout << ans << "\n";
    return 0;
}
