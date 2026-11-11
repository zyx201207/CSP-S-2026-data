#include <bits/stdc++.h>
using namespace std;
//#define int long long
bool a[2000001][31];
bool vis[2000001];
signed main()
{
    //freopen("and5.in","r",stdin);
    //freopen("and5.out","w",stdout);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(vis,1,sizeof(vis));
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        int temp = 0;
        while(x > 0)
        {
            temp++;
            if(x % 2 == 1)
            {
                a[i][temp] = 1;
            }
            x /= 2;
        }
    }
    int ans = 0;
    for(int i = 31;i >= 1;i--)
    {
        ans *= 2;
        int cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            cnt += (vis[j] * a[j][i]);
        }
        if(cnt >= m)
        {
            ans += 1;
            for(int j = 1;j <= n;j++)
            {
                if(a[j][i] == 0)
                {
                    vis[j] = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
