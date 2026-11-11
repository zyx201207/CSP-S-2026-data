#include <bits/stdc++.h>
using namespace std;

int n;
int d;
int dt(int v, int x[])
{
    cout << v;
    if (v == n) return 0;
    int res = 0;
    for(int i = v + 1; i < n; i++)
    {
        if (x[i] - d <= x[v])
        {
            res = x[i] - x[v];
        }
        else break;
    }
    return dt(v + res, x) + 1;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "r", stdout);

    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int d, co = 0;
        cin >> n >> d;
        int x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        cout << dt(0, x);

    }
    return 0;
}

