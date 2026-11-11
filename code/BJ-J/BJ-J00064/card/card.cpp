#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500010], ans[300010] = {0}, last[300010];
bool b[300010] = {false};

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int num = a[i];
        ans[num]++;
        while(last[num] < n)
        {
            num = a[last[num] + 1];
            ans[num]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
