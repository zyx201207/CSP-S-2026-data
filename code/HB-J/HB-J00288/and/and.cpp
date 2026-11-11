#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int d1()
{
    sort(a + 1, a + n + 1, greater<>());
    int ans = a[1];
    for(int i = 1; i <= m; i++)
        ans &= a[i];
    cout << ans;
}
int ans = 0;
void dfs(int s, int cnt, int res)
{
    // for(int i = 1; i <= s; i++)
    //     cerr << ' ';
    // cerr << s << ' ' << cnt << ' ' << res << '\n';
    if(cnt > m)
        return;
    if(s == n && cnt == m)
    {
        ans = max(res, ans);
        return;
    }
    if(s >= n)
        return;
    dfs(s + 1, cnt + 1, res & a[s + 1]);
    dfs(s + 1, cnt, res);
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 20)
    {
        dfs(1, 1, a[1]);
        dfs(1, 0, INT_MAX);
        cout << ans;
    }
    else if(n <= 2000 && m == 1)
    {
        int maxn = 0;
        for(int i = 1; i <= n; i++)
        {
            maxn = max(a[i], maxn);
        }
        cout << maxn;
    }
    else if(m == n)
    {
        int res = a[1];
        for(int i = 1; i <= n; i++)
        {
            res &= a[i];
        }
        cout << res;
    }
    else if(m == 2)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j)
                    ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
    } 
    else if(m == n - 1)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int res = INT_MAX;
            for(int j = 1; j <= n; j++)
            {
                if(j == i)
                    continue;
                res &= a[j];
            }
            ans = max(ans, res);
        }
        cout << ans;
    } else{
        d1();
    }
    return 0;
}