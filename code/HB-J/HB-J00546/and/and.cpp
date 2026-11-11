#include <bits/stdc++.h>
using namespace std;
int t[200005];
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
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1, cmp);
    int ans = 0;
    for (int i = 30; i >= 1; i--)
    {
        int k = 1 << (i - 1), cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (t[j] >= k)
            {
                cnt ++;
            }
        }
        if (cnt >= m)
        {
            ans += k;
            n = cnt;
            for (int j = 1; j <= cnt; j++)
            {
                t[j] -= k;
            }
        }
    }
    cout << ans;
    return 0;
}
