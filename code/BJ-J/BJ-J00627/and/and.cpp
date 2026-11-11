#include <bits/stdc++.h>
using namespace std;

int a[200005], x[200005];
int n, m;
long long ans;
bool flag[200005];
int k[200005];
void dfs(int cnt)
{
    if (cnt > m)
    {
        int sum = x[1];
        for (int i = 2; i <= m; i++)
        {
            sum = sum & x[i];
        }
        ans = max(ans, sum);
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            x[cnt] = a[i];
            flag[i] = 1;
            dfs(cnt + 1);
            flag[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    long long maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if (n <= 20)
    {
        dfs(0);
        cout <<ans;
        return 0;
    }
    if (m == 1)
    {
        cout << maxx;
    }
    else if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans = max(ans,(a[i] & a[j]));
            }
        }
        cout << ans;
    }
    else if(m == n)
    {
        ans = a[1];
        for (int i = 2; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
