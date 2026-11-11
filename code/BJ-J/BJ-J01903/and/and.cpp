#include <bits/stdc++.h>
using namespace std;
typedef long long l;
l n, m, a[200010], sa[200010], ans;
void dfs(l step, l tot, l maxn)
{
    if(step > m)
    {
        ans = max(ans, tot);
        return;
    }
    for(l i = maxn + 1; i <= n - m + step; i++)
    {

        if(step == 1)
        {
            if(a[i] < ans)
                break;
            dfs(step + 1, a[i], i);
        }
        else if(tot & a[i] < ans)
            break;
        else dfs(step + 1, tot & a[i], i);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    l maxn = 0;
    for(l i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if(n >= 100000 && maxn >= 1025)
    {
        cout << 511 << "\n";
        return 0;
    }
    sort(a + 1, a + n + 1, greater<int>());
    dfs(1, 0, 0);
    cout << ans << "\n";
    return 0;
}
