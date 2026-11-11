#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], maxn = -0x3f3f3f;

bool cmp(int x, int y)
{
    return x > y;
}

void solve0()
{
    sort(a + 1, a + n + 1);
    cout << a[n];
}

void solve00()
{
    int ans = a[1];
    for (int i = 2; i <= n; i++)
        ans = (ans & a[i]);
    cout << ans;
}

void solve01()
{
    sort(a + 1, a + n + 1, cmp);
    int ans = a[1];
    for (int i = 2; i <= m; i++)
        ans = (ans & a[i]);
    cout << ans;
}

void solve02()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            maxn = max(maxn, (a[i] & a[j]));
    cout << maxn;
}

void dfs(int step, int cnt, int now)
{
    if (cnt >= m)
    {
        maxn = max(maxn, now);
        return;
    }
    if (step > n) return;
    if (now == 0) return;
    if (now < maxn) return;

    if (now == -1)
    {
        dfs(step + 1, cnt + 1, a[step]);
        dfs(step + 1, cnt, now);
    }
    else
    {
        dfs(step + 1, cnt + 1, (now & a[step]));
        dfs(step + 1, cnt, now);
    }
}

void solve1()
{
    dfs(1, 0, -1);
    cout << maxn;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1) solve0();
    if (m == n) solve00();
    if (m == 2) solve02();
    else if (n <= 2000) solve1();
    else if (n <= 200005) solve01();
    return 0;
}
