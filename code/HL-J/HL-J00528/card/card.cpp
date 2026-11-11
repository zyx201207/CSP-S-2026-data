#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = (int)5e5 + 5;
int n, m, a[MAXN];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        vector<int> v;
        for (int j = i; j <= n; j++)
        {
            int p = lower_bound(v.begin(), v.end(), a[j]) - v.begin();
            if (v[p] == a[j])
            {
                do
                {
                    v.pop_back();
                }
                while(v.front() != a[j]);
            }
        }
        while (!v.empty())
        {
            if (v.front() == m)
                cnt++;
            v.pop_back();
        }
        cout << cnt << ' ';

    }
    return 0;
}
