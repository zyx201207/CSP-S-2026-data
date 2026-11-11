#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w[500010];
ll a[510][50010],t[510][50010];
ll k[510];
ll sum[510];

struct node
{
    ll s,e;
}r[1000010];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ll c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;

    for(ll i = 1;i <= m;i++)
    {
        cin >> w[i];
    }

    for(ll i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(ll j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            sum[a[i][j]]++;
        }
    }

    for(ll v = 1;v <= q;v++)
    {
        cin >> r[v].s >> r[v].e;

        ll ans = 0;
        ll s = 0;
        ll l1 = 0,l2 = 0,tr = 0;
        for(ll i = 1;i <= n;i++)
        {
            for(ll j = 1;j <= k[i];j++)
            {
                if(a[i][j] == r[v].s)
                {
                    ans += t[i][j] + w[r[v].s];
                    l1 = i;
                    s++;
                }
                if(a[i][j] == r[v].e)
                {
                    ans += t[i][j] + w[r[v].e];
                    l2 = i;
                    s++;
                }
            }
            if(sum[i] >= 2) tr = i;
            if(s == 2) break;
        }


        if(l1 == l2)
        {
            cout << ans << "\n";
            continue;
        }

        for(ll i = 1;i <= n;i++)
        {
            for(ll j = 1;j <= k[i];j++)
            {
                if(a[i][j] == tr)
                {
                    ans += t[i][j];
                }
            }
        }

        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
