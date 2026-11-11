#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,a[500001],la[300001] = {},ans[300001] = {};
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        la[a[i]] = i;
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            if (la[a[j]] != j)
            {
                j = la[a[j]];
            }
            ans[a[j]]++;
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}