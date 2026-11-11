#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Solve_brute
{
    const int maxn = 5010;
    int n,d,x[maxn],path[maxn][maxn],dis[maxn][maxn],sum[maxn][maxn];
    void solve()
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)cin >> x[i];
        int ans = 0;
        for(int i = 1;i <= n;i++)for(int j = 1;j <= n;j++)path[i][j] = dis[i][j] = sum[i][j] = 0;
        for(int i = 1;i <= n;i++)
        {
            int l = i,r = i;
            path[i][i] = sum[i][i] = 1;
            for(int j = i + 1;j <= n;j++)
            {
                while(l <= j && x[j] - x[l] > d)l++;r = max(l,r);
                while(r < j - 1 && dis[i][l] == dis[i][r + 1])r++;
                dis[i][j] = dis[i][l] + 1;path[i][j] = sum[i][r] - sum[i][l - 1];
                ans += (path[i][j] == 2);sum[i][j] = sum[i][j - 1] + path[i][j];
            }
        }
        cout << ans << '\n';
    }
}
namespace Solve_A
{
    const int maxn = 2e6 + 10;
    int n,d,x[maxn],path[maxn],dis[maxn],sum[maxn],cnt[maxn];
    void solve()
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)cin >> x[i];
        for(int i = 1;i <= n;i++)path[i] = dis[i] = sum[i] = 0;
        int l = 1,r = 1,ans = 0;path[1] = sum[1] = 1;
        for(int j = 2;j <= n;j++)
        {
            while(l <= j && x[j] - x[l] > d)l++;r = max(l,r);
            while(r < j - 1 && dis[l] == dis[r + 1])r++;
            dis[j] = dis[l] + 1;path[j] = sum[r] - sum[l - 1];
            cnt[j] = (path[j] == 2);sum[j] = sum[j - 1] + path[j];
        }
        for(int i = 1;i <= n;i++)cnt[i] += cnt[i - 1];
        for(int i = 1;i <= n;i++)ans += cnt[n - i + 1];
        cout << ans << '\n';
    }
}
bool flagA,flagB,flagC;
void solve()
{
    if(!flagA && !flagB && !flagC)Solve_brute::solve();
    else if(flagA)Solve_A::solve();
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;cin >> c >> T;
    if(c == 11 || c == 12)flagA = 1;
    else if(c == 13 || c == 14)flagB = 1;
    else if(c == 15 || c == 16 || c == 17 || c == 18)flagC = 1;
    while(T--)solve();return 0;
}

/*
48 pts
1~12

蓝/紫 ？

破防了。/ll
*/