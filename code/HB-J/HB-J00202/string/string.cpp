#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
ll a[200010];
char c[200010];
ll ans;

inline ll llmin(ll a,ll b)
{
    return (a < b ? a : b);
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i = 0;i < n;i++)
        scanf("%lld %c",&a[i],&c[i]);
    ll i = 0,j = n - 1;
    while(i < j)
    {
        if(c[i] == c[j])
        {
            ll ad = llmin(a[i],a[j]);
            a[i] -= ad;
            if(a[i] == 0)
                i++;
            a[j] -= ad;
            if(a[j] == 0)
                j--;
        }
        else
        {
            ll ad = llmin(a[i],a[j]);
            a[i] -= ad;
            if(a[i] == 0)
                i++;
            a[j] -= ad;
            if(a[j] == 0)
                j--;
            ans += ad;
        }
    }
    printf("%lld",ans);
    return 0;
}