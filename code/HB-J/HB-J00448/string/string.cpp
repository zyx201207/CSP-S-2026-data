#include <bits/stdc++.h>
using namespace std;
int main ()
{
    //freopen("string.in", "r", stdin);
    //freopen("string.out", "w", stdout);
    int n, sum = 0, l = 1, r;
    cin >> n;
    r = n;
    int a[n + 1];
    char c[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    while (l < r)
    {
        if (c[l] != c[r])
        {
            if (a[r] > a[l])
            {
                a[r] = max(a[l], a[r]) - min(a[l], a[r]);
                sum += a[l];
                l++;
            }
            else if (a[r] < a[l])
            {
                a[l] = max(a[l], a[r]) - min(a[l], a[r]);
                sum += a[r];
                r--;
            }
            else
            {
                sum += a[l];
                l++;
                r--;
            }
        }
        else
        {
            if (a[r] > a[l])
            {
                a[r] = max(a[l], a[r]) - min(a[l], a[r]);
                l++;
            }
            else if (a[r] < a[l])
            {
                a[l] = max(a[l], a[r]) - min(a[l], a[r]);
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout << sum;
    return 0;
}
