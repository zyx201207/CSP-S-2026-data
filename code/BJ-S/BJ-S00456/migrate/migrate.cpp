#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int c,t,n,d,x[N],ed;
map<int,int> mp;
void dfs(int u,int sum)
{
    if (u == ed)
    {
        mp[sum]++;
        return;
    }
    for (int i = u+1; i<=ed && x[i]-x[u]<=d; i++)
        dfs(i,sum+1);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int i,j;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        int ans=0;
        for (i = 1; i <= n; i++)
            cin >> x[i];
        mp.clear();
        for (i = 1; i < n; i++)
            for (j = i+1; j <= n; j++)
            {
                ed = j;
                dfs(i,0);
                for (auto [a,b]:mp)
                {
                    if (b == 2)
                        ans++;
                    break;
                }
            }
        cout << ans << "\n";
    }
    return 0;
}