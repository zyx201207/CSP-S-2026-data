#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e6+7;
ll n,c,t;
ll x[maxn],d,a[maxn],m,f[maxn],sum[maxn],ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        memset(x,(long long)0,sizeof(x));
        ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        for (int u = 1;u <= n-2;u++)
        {
            memset(sum,0x3f3f3f3f3f3f3f3f,sizeof(sum));
            memset(f,(long long)0,sizeof(f));
            sum[u]=0;
            for (int v = u;v<=n;v++)
            {
                if (f[v]==2)
                {
                    ans++;
                }
                int j = v;
                while(j <= n && x[j]-x[v] <= d)
                {
                    if (sum[j] < sum[v]+1)
                    {
                        j++;
                        continue;
                    }
                    else if (sum[j]==sum[v]+1)
                    {
                        f[j]++;
                    }
                    else
                    {
                        sum[j]=sum[v]+1;
                        f[j]=1;
                    }
                    j++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
