#include <bits/stdc++.h>
using namespace std;
int a[200010], cnt1[200010];
int shu1(int x)
{
    int cnt = 0;
    while (x != 0)
    {
        x -= (x & (-1));
        cnt++;
    }
    return cnt;
}
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int maxn = -1;
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxn = max(maxn, a[i]);
        }
        cout << maxn;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt1[i] = shu1(a[i]);
    }
    sort(cnt1+1, cnt1+n+1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans & cnt1[i]);
    }
    cout << ans;
    return 0;
}
