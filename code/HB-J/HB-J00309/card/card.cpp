#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N];
int real_ans[M];

void solve1()
{
    for (int i = 1; i <= n; ++i)
        cout << 1 << ' ';

    return;
}
void solve2()
{
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> vis(n + 1, 0);
    vector<int> lst(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        set<int> ans, tmp;
        for (int j = 1; j <= m; ++j)
            vis[j] = 0;
        for (int j = i; j <= n; ++j)
        {
            if (vis[a[j]])
            {
                // ans = tmp, ans.insert(a[j]);
                for (int x = vis[a[j]]; x <= j; ++x)
                    vis[a[x]] = 0, ans.erase(a[x]);

                // ans.insert(a[j]), vis[a[j]] = j;
            }
            // else
            vis[a[j]] = j, ans.insert(a[j]);
        }
        for (auto j : ans)
            real_ans[j]++;
    }
    for (int i = 1; i <= m; ++i)
        cout << real_ans[i] << ' ';
    return;
}

void solve3()
{
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> nex(n + 1, 0), vis(m + 1, 0);
    vector<set<int>> dp(n + 5);
    set<int> tmp;
    tmp.clear();
    dp[n + 1] = tmp;
    for (int i = n; i > 0; --i)
    {
        if (vis[a[i]])
            nex[i] = vis[a[i]];
        vis[a[i]] = i;
        if (!nex[i])
            dp[i] = dp[i + 1], dp[i].insert(a[i]);
        else
            dp[i] = dp[nex[i]];
    }
    for (int i = 1; i <= m; ++i)
        vis[i] = 0;
    for (int i = 1; i <= n; ++i)
        for (auto j : dp[i])
            vis[j]++;

    for (int i = 1; i <= m; ++i)
        cout << vis[i] << ' ';
    return;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if (m == 1)
        solve1();

    else if (n <= 500)
        solve2();

    else
        solve3();
}
