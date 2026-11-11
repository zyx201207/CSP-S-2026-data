#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], nxt[500005], lst[300005], head[500005], d[500005], ans[300005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], nxt[lst[a[i]]] = i, lst[a[i]] = i;
    for (int i = n; i >= 1; i--)
    {
        d[i] = 1;
        if (!nxt[i]) head[i] = i;
        else head[i] = head[nxt[i]];
        // cout << head[i] << '\n';
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (head[i] != i) d[head[i]] += d[i], d[i] = 0;
        else d[i + 1] += d[i];
    }
    for (int i = 1; i <= n; i++) ans[a[i]] += d[i];
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
/*
4 3
1 2 1 3
*/
// 11:21
/*
现在是11:26，我现在慌的一批
估分100+100+100+100=400？这不对吧
别挂别挂别挂
*/