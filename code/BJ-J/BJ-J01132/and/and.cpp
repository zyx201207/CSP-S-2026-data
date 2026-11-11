#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005], d[200005][40], vis[200005], ans=0;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        d[i][0]=a[i]&1;
        d[i][1]=a[i]&2;
        for (int j = 2; j <= 30; j++)
        {
            d[i][j]=a[i]&(2<<(j-1));
        }
    }
    ll cnt=n;
    for (int j = 30; j >=0; j--)
    {
        ll t=0;
        for (int i=0; i < n; i++)
        {
            if (d[i][j]>0 && vis[i]==0)
            {
                t++;

            }
        }
        if (t>=m)
        {
            ans=ans+(1<<j);
            for (int i=0; i < n; i++)
            {
                if (d[i][j]==0)
                {
                    vis[i]=1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
