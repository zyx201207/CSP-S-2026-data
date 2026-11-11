#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    int a[500005], ans = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[n] == a[i])
                ans++;
        }
        m--;
    }
    cout << ans / 2;
    return 0;
}
