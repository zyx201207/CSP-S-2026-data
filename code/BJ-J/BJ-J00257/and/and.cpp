#include <bits/stdc++.h>
using namespace std;
long long n, m, a[2005], ans, sum;
void dfs(long long m, long long cnt, long long i)
{
    if (m == 0)
    {
        sum = max(sum, cnt);
        return ;
    }
    if (m != 0 && i == n + 1)
    {
        return ;
    }
    dfs(m - 1, cnt & a[i], i + 1);
    dfs(m, cnt, i + 1);
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    if (m == 1)
    {
        cout << a[1] << endl;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    ans = max(ans, (a[i] & a[j]));
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (m == n)
    {
        ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans << endl;
        return 0;
    }
    if (n <= 20)
    {
        for (int i = 1; i <= n - m + 1; i++)
        {
            dfs(m - 1, a[i], i + 1);
        }
        cout << sum << endl;
        return 0;
    }
    return 0;
}