#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[200000], ans;

void dfs (int dep, int start, int res)
{
    if (start == n)
        return;
    if (dep == m)
    {
        ans = max(ans, res);
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (res == -1)
            dfs(dep + 1, i + 1, a[i]);
        else
        {
            if ((res & a[i]) < ans)
                return;
            dfs(dep + 1, i + 1, res & a[i]);
        }
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "W", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, 0, -1);
    cout << ans;
    return 0;
}
