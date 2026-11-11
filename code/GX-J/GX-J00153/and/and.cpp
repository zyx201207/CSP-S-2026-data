#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= m; j++)
        {
            b[i] = a[i] && a[i + j];
        }
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << b[1];
    }
    return 0;
}
