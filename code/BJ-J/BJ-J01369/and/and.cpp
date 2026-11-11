#include <iostream>
using namespace std;
int a[100000];
int maxn = 0;
int n, m;
void dfs(int step, int q, int sum)
{
    if(q == m)
    {
        maxn = max(maxn, sum);
        return;
    }
    if(step >= n)
    {
        return;
    }
    if(sum == 0)
    {
        dfs(step + 1, q, sum);
        dfs(step + 1, q + 1, a[step + 1]);
    }
    else
    {
        dfs(step + 1, q, sum);
        dfs(step + 1, q + 1, sum & a[step + 1]);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 20)
    {
        dfs(1, 0, 0);
        dfs(1, 1, a[1]);
        cout << maxn;
        return 0;
    }
    if(m == 1)
    {
        maxn = 0;
        for(int i = 1; i <= n; i++)
        {
            maxn = max(maxn, a[i]);
        }
        cout << maxn;
        return 0;
    }
    if(m == 2)
    {
        maxn = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                maxn = max(maxn, a[i] & a[j]);
            }
        }
        cout << maxn;
        return 0;
    }
    if(m == n)
    {
        maxn = a[1];
        for(int i = 2; i <= n; i++)
        {
            maxn = maxn & a[i];
        }
        cout << maxn;
        return 0;
    }
    if(m == n - 1)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int p = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i != j)
                {
                    if(p == 0)
                    {
                        p = a[j];
                    }
                    else
                    {
                        p = p & a[j];
                    }
                }
            }
            ans = max(ans, p);
        }
        cout << ans;
    }
    return 0;
}