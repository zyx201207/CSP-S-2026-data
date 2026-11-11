#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], s = 0;
void dg(int x, int y, int z)
{
    if (x >= m)
    {
        s = max(s, z);
        return;
    }
    for (int i = y; i <= n - m + x; i++)
    {
        dg(x + 1, i + 1, z & a[i]);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dg(0, 0, INT_MAX);
    cout << s;
    return 0;
}
