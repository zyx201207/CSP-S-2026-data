#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,ans;
ll a[500005];
int f;
void doo(ll b,ll c,ll d)
{
    while(1)
    {
        ll j = ans * (a[b] - d);
        if(c >= j)
        {
            ans++;
            c -= j;
            d = a[b];
            b++;
        }
        else
            return;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    ll x,t,tt,tn;
    if(n % 2 == 0)
        t = n / 2;
    else
        t = n / 2 + 1;
    tt = t;
    x = a[t];
    for(int i = t + 1;i <= n;i++)
    {
        if(a[i] == x)
            ans++;
        else
        {
            tn = i;
            break;
        }
    }
    while(m)
    {
        if(!t)
        {
            f = 1;
            break;
        }
        ll cha = x - a[t];
        if(m >= cha)
        {
            m -= cha;
            a[t] += cha;
            t--;
            ans++;
        }
        else
        {
            f = 2;
            break;
        }
    }
    if(f == 1)
    {
        doo(tn,m,x);
    }
    cout << ans;
    return 0;
}