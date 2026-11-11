#include <bits/stdc++.h>

using namespace std;

int n;

long long a[200010];
char c[200010];

long long ans;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];

    int l = 1, r = n;

    while (l < r)
    {
        int mn = min(a[l], a[r]);
        if (c[l] == c[r])
        {
            a[l] -= mn;
            a[r] -= mn;
            if (a[l] == 0)
                l++;
            if (a[r] == 0)
                r--;
        }
        else
        {
            ans += mn;
            a[l] -= mn;
            a[r] -= mn;
            if (a[l] == 0)
                l++;
            if (a[r] == 0)
                r--;
        }
    }
    cout << ans;
    return 0;
}