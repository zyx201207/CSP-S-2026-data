#include <bits/stdc++.h>
using namespace std;

long long a[200010];
long long first[200010];
long long last[200010];
long long n, m;
long long maxnnn = -1e9;

bool check2()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != (i - 1))
        {
            return false;
        }
    }
    return true;
}

bool check1(long long a)
{
    while (a != 1)
    {
        if (a % 2 != 0)
        {
            return false;
        }
        a /= 2;
    }
    return true;
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (!check1(a[i] + 1))
        {
            return false;
        }
    }
    return true;
}

void dfs(int step, int choose, long long num)
{
    if (step == n)
    {
        if (choose == m)
        {
            maxnnn = max(maxnnn, num);
        }
        return;
    }
    if (choose == m)
    {
        maxnnn = max(maxnnn, num);
        return;
    }
    if (choose == 0)
    {
        dfs(step + 1, 1, a[step]);
        dfs(step + 1, 0, 0);
    }
    dfs(step + 1, choose + 1, (num & a[step]));
    dfs(step + 1, choose, num);
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >>m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[1];
    }
    else if (m == 2)
    {
        long long maxn = -1e9;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                long long now = (a[i] & a[j]);
                maxn = max(maxn, now);
            }
        }
        cout << maxn;
    }
    else if (m == n)
    {
        long long ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = (ans & a[i]);
        }
        cout << ans;
    }
    else if (m == n - 1)
    {
        long long maxn = -1e9;
        first[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            first[i] = (first[i - 1] & a[i]);
        }
        last[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
        {
            last[i] = (last[i + 1] & a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            maxn = max(maxn, (first[i - 1] & last[i + 1]));
        }
        cout << maxn;
    }
    else if (check())
    {
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[m];
    }
    else if (check2() && check1(n))
    {
        long long ans = a[n];
        for (int i = n - 1; i >= n - m + 1; i--)
        {
            ans = (ans & a[i]);
        }
        cout << ans;
    }
    else
    {
        dfs(1, 0, 0);
        cout << maxnnn;
    }
    return 0;
}
