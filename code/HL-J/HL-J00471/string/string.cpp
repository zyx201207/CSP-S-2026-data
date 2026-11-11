#include <bits/stdc++.h>
using namespace std;
int n, a[200005], num, sum;
char b[200005];
string c, d;
int main()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    for (int i=1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        for (int j=1; j <= a[i]; j++)
        {
            c += b[i];
        }
        num += a[i];
    }
    for (int i=num; i >= 1; i--)
    {
        d += c[i];
    }
    for (int i=1; i <= num; i++)
    {
        if (c[i] != d[i])
            sum++;
    }
    cout << sum;
    fclose (stdin);
    fclose (stdout);
    return 0;
}
