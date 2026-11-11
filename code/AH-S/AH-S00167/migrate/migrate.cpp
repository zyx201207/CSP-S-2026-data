#include <bits/stdc++.h>
using namespace std;
int n[100005], d[100005], x[100005][100005], ans[100005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c, t;
    cin >> c >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n[i] >> d[i];
        for (int j = 1; j <= n[i]; j++)
        {
            cin >> x[i][j];
        }
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            if(x[i][1] + d[i] >= x[i][j] && x[i][n[i] - d[i] <= x[i][j])
            {
                ans[i]++;
            }
        }
    }
    for (int i = 1; i <= t; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
