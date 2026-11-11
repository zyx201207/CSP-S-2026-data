#include <bits/stdc++.h>
using namespace std;

int a[500005], b[500005], p[500005], ans[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        memset(p, 0, sizeof(p));
        memset(b, 0, sizeof(b));
        int t = 0;
        for (int j = i; j <= n; j++)
        {
            if (!p[a[j]]) b[++t] = a[j], p[a[j]] = t;
            else
            {
                for (int k = p[a[j]] + 1; k <= t; k++) p[b[k]] = 0;
                t = p[a[j]];
            }
        }
        for (int j = 1; j <= t; j++) ans[b[j]]++;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}