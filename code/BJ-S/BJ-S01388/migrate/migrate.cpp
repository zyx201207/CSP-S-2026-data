#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,d,sum[500005],k = 0,minn = 600000;
int ans = 0,c,t;
bool flag = true;
void dfs(int x,int y,int point)
{
    if(x == y)
    {
        sum[k] = point;
        minn = min(minn,sum[k]);
        k++;
        return ;
    }
    for (int i = x + 1;i <= n;i++)
    {
        if (a[i] - a[x] <= d) dfs(i,y,point + 1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        long long ks = a[2] - a[1];
        for (int i = 3;i <= n;i++)
        {
            if (a[i] - a[i - 1] != ks) flag = false;
        }
        if(flag)
        {
            if (d < ks * 2)
            {
                cout << 0 << '\n';
                continue;
            }
            else
            {
                cout << (n * n - 4 - 3 * n) / 4 << '\n';
                continue;
            }
        }
        for (int i = 1;i < n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                k = 1,minn = 600000;
                long long cnt = 0;
                memset(sum,0,sizeof(sum));
                dfs(i,j,0);
                for (int i = 1;i <= k;i++)
                {
                    if (sum[i] == minn)
                    {
                        cnt++;
                    }
                }
                if (cnt == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
