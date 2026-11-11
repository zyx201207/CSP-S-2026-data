#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5;
long long n, m;
vector<long long> a;

long long dfs(int last_num, int now_id, int ok)
{
    if (ok == m)
    {
        return last_num;
    }
    long long ans = dfs(last_num & a[now_id], now_id + 1, ok + 1);
    if (now_id >= n - m + ok + 1)
    {
        ans = max(ans, dfs(last_num, now_id + 1, ok));
    }
    return ans;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    a.resize(n);
    long long mx = 0;
    long long x;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i == 0)
        {
            x = a[i];
        }
        else
        {
            x &= a[i];
        }
        mx = max(mx,a[i]);
    }

    if (m == 1)
    {
        cout << mx;
        return 0;
    }
    if (m == n)
    {
        cout << x;
        return 0;
    }
    if (m == 2)
    {
        long long ans = 0,cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if (n <= 20)
    {
        long long ans = 0;
        for (int i = 0; i < n - m + 1; ++i)
        {
            ans = max(ans, dfs(a[i], i + 1, 1));
        }
        cout << ans;
        return 0;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long ans = a[0];
    for (int i = 1; i < m; ++i)
    {
        ans &= a[i];
    }
    cout << ans;

    return 0;
}
