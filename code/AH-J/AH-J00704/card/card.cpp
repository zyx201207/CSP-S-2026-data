#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[5010],cnt[3010];
vector <ll> v;
bool f1[3010];
int main ()
{
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    scanf ("%lld %lld",&n,&m);
    for (ll i = 1;i <= n;i++) scanf ("%lld",&a[i]);
    for (ll i = 1;i <= n;i++)
    {
        memset (f1,0,sizeof (f1));
        for (ll j = i;j <= n;j++)
        {
            if (f1[a[j]])
            {
                ll len = v.size (),pos;
                for (ll k = 0;k < len;k++)
                {
                    if (v[k] == a[j])
                    {
                        pos = k;
                        break;
                    }
                }
                for (ll k = 0;k < pos;k++)
                {
                    f1[v[k]] = 0;
                }
                v.erase (v.begin (),v.begin ()+pos);
            }
            else
            {
                v.push_back (a[j]);
                f1[a[j]] = 1;
            }
        }
        for (ll j = 1;j <= m;j++)
        {
            if (f1[j])
            {
                cnt[j]++;
            }
        }
        v.clear ();
    }
    for (ll i = 1;i <= m;i++) cout << cnt[i] << " ";
    return 0;
}
