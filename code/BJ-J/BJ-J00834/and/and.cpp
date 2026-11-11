#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int arr01[N], ans;
void dfs(int pos, int n, int m, int cnt, int sum)
{
    if (pos > n)
    {
        ans = max(ans, sum);
        return;
    }
    if (m == n - pos + cnt + 1)
    {
        dfs(pos+1, n, m, cnt+1, sum&arr01[pos]);
    }
    else if (cnt == m)
    {
        dfs(pos+1, n, m, cnt, sum);
    }
    else
    {
        dfs(pos+1, n, m, cnt+1, sum&arr01[pos]);
        dfs(pos+1, n, m, cnt, sum);
    }
}
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
    int maxn = 0, sumn = 2147483647;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr01[i];
        maxn = max(maxn, arr01[i]);
        sumn &= arr01[i];
    }
    if (m == 1)
    {
        cout << maxn << '\n';
    }
    else if (m == n)
    {
        cout << sumn << '\n';
    }
    else if (m == 2)
    {
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ans = max(ans, arr01[i]&arr01[j]);
            }
        }
        cout << ans << '\n';
    }
    else if (n <= 30)
    {
        dfs(1, n, m, 0, 2147483647);
        cout << ans << '\n';
    }
    else
    {
        sort(arr01+1, arr01+n+1, cmp);
        ans = 2147483647;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans &= arr01[i];
            cnt++;
            if (cnt == m) break;
        }
        cout << ans << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
