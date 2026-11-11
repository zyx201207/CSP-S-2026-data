#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], ans[300005];
vector <int> v[300005], b[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i], v[a[i]].push_back(i);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < v[i].size() - 1; ++j)
        {
            for (int k = v[i][j]; k < v[i][j+1]; ++k)
            {
                b[k].push_back(v[i][j]);
            }
        }
    }
    for (int i = n; i >= 1; --i)
    {
        if(!ans[a[i]])
        {
            ans[a[i]] = i;
            int tmp = 0, minn = 1e9;
            for (int j = 0; j < b[i].size(); ++j)
            {
                if(b[i][j] < minn)
                {
                    tmp = j;
                    minn = b[i][j];
                }
            }
            if(b[i].size()) ans[a[i]] = i - b[i][tmp];
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
    return 0;
}