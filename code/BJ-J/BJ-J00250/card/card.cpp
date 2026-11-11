#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], cnt[300005];
vector<int> card[300005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) flag = 0;
        card[a[i]].push_back(i);
    }
    if (flag && (1ll * n * m >= 1000000000))
    {
        for (int i = 1; i <= m; i++)
        {
            cout << card[i][card[i].size() - 1] << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (card[a[j]][card[a[j]].size() - 1] == j)
            {
                cnt[a[j]]++;
            }
            else
            {
                j = card[a[j]][card[a[j]].size() - 1] - 1;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}