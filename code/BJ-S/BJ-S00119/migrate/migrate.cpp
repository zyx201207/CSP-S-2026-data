#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long c, t, n, d, ans = 0;
int x[N];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >>c >>t;
    while (t--)
    {
        vector<int> v[N];
        cin >>n >>d;
        for (long long i = 1; i <= n; i++) cin >>x[i];
        for (long long i = 2; i <= n; i++)
        {
            int vis[N];
            for (long long j = 0; j <= n; j++) vis[j] = 0;
            for (long long j = i - 1; j >= 1 && x[i] - x[j] <= d; j--)
            {
                v[i].push_back(j);
            }
            for (long long j = 0; j < v[i].size(); j++)
            {
                for (long long k = 0; k < v[v[i][j]].size(); k++)
                {
                    vis[v[ v[i][j] ][k] ]++;
                }
            }
            for (long long j = max(1ll, i - 2 * d); j < max(0ll, i - d); j++) if (vis[j] == 2) ans++;
        }
        cout <<ans <<endl;
        ans = 0;
    }
}
