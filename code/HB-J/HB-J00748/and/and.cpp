#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
bool a[200010][35];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        // cin >> x;
        // cout << x << " ";
        for (int j = 0; j < 35; j++)
        {
            a[i][j] = x & 1;
            x >>= 1;
        }
    }
    vector <int> lst, now;
    for (int i = 1; i <= n; i++)
    {
        lst.push_back(i);
        // for (int j = 0; j < 10; j++)
        // {
        //     cout << a[i][j];
        // }
        // cout << "\n";
    }
    for (int i = 30; i >= 0; i--)
    {
        for (auto j : lst)
        {
            if (a[j][i])
            {
                now.push_back(j);
            }
        }
        if (now.size() >= m)
        {
            ans += (1 << i);
            lst = now;
        }
        now.clear();
    }
    cout << ans << endl;
    return 0;
}