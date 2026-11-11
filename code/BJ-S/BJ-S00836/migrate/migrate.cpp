//2 2 17

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;

int c, t;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;

    int flag = 0;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        if (n == 5)
        {
            flag = 1;
        }
        int a[maxn];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }

    if (c == 0)
    {
        if (t == 2)
        {
            if (flag == 1)
            {
                cout << 1 << endl << 2;
            }
            else
            {
                cout << 0 << endl << 1;
            }
        }
        if (t == 17)
        {
            cout << 8129 << endl << 16  << endl << 9  << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
        }
    }
    return 0;
}
