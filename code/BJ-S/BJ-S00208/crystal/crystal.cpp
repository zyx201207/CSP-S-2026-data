#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[500010];
ll c[500010];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ll n,m;
    cin >> n >> m;

    for(ll i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    sort(a + 1,a + 1 + n);

    for(ll i = 1;i <= n;i++)
    {
        if(i == 1) c[i] = a[i];
        c[i] = a[i] - a[i - 1];
    }


    ll ans = 0,sum = 0;
    for(ll i = 1;i <= n;i++)
    {
        sum += c[i] * (i - 1);

        if(sum <= m)
        {
            ans++;
        }
    }

    cout << ans << "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
