#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, m, a[2000001], s = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 3; i++)
        {
            if ((a[i + 1] - a[i] == m) || (a[i + 2] - a[i] > m))
            {
                continue;
            }
            for (int j = i + 3; j < n; j++)
            {
                if ((a[j] - a[i + 2] == m) || (a[j] - a[i + 1] > m))
                {
                    break;
                }
                s++;
            }
        }
        cout << s << endl;
    }
    return 0;
}

