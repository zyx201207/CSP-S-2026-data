#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;
ll a[200010];

inline ll llmax(ll a,ll b)
{
    return (a > b ? a : b);
}

bool gt(ll a,ll b)
{
    return a > b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i = 0;i < n;i++)
        scanf("%lld",&a[i]);
    if(m == n)
    {
        ll ans = a[0];
        for(ll i = 1;i < n;i++)
            ans &= a[i];
        printf("%lld",ans);
        return 0;
    }
    if(m == 1)
    {
        ll ans;
        for(ll i = 0;i < n;i++)
            ans = llmax(ans,a[i]);
        printf("%lld",ans);
        return 0;
    }
    if(m == 2)
    {
        ll ans = 0;
        for(ll i = 0;i < n;i++)
            for(ll j = i + 1;j < n;j++)
            {
                ll band = a[i] & a[j];
                if(band > ans)
                    ans = band;
            }
        printf("%lld",ans);
        return 0;
    }
    if(m == 3)
    {
        ll ans = 0;
        for(ll i = 0;i < n;i++)
            for(ll j = i + 1;j < n;j++)
                for(ll k = j + 1;k < n;k++)
                {
                    ll band = a[i] & a[j] & a[k];
                    if(band > ans)
                        ans = band;
                }
        printf("%lld",ans);
        return 0;
    }
    if(m == 4)
    {
        ll ans = 0;
        for(ll i = 0;i < n;i++)
            for(ll j = i + 1;j < n;j++)
                for(ll k = j + 1;k < n;k++)
                    for(ll iiii = k + 1;iiii < n;iiii++)
                    {
                        ll band = a[i] & a[j] & a[k] & a[iiii];
                        if(band > ans)
                            ans = band;
                    }
        printf("%lld",ans);
        return 0;
    }
    if(m == 5)
    {
        ll ans = 0;
        for(ll i = 0;i < n;i++)
            for(ll j = i + 1;j < n;j++)
                for(ll k = j + 1;k < n;k++)
                    for(ll iiii = k + 1;iiii < n;iiii++)
                        for(ll jjjj = iiii + 1;jjjj < n;jjjj++)
                        {
                            ll band = a[i] & a[j] & a[k] & a[iiii] & a[jjjj];
                            if(band > ans)
                                ans = band;
                        }
        printf("%lld",ans);
        return 0;
    }
    if(m == 6)
    {
        ll ans = 0;
        for(ll i = 0;i < n;i++)
            for(ll j = i + 1;j < n;j++)
                for(ll k = j + 1;k < n;k++)
                    for(ll iiii = k + 1;iiii < n;iiii++)
                        for(ll jjjj = iiii + 1;jjjj < n;jjjj++)
                            for(ll kkkk = jjjj + 1;kkkk < n;kkkk++)
                            {
                                ll band = a[i] & a[j] & a[k] & a[iiii] & a[jjjj] & a[kkkk];
                                if(band > ans)
                                    ans = band;
                            }
        printf("%lld",ans);
        return 0;
    }
    ll mxl = 0;
    for(ll i = 0;i < n;i++)
        mxl = llmax(mxl,a[i]);
    if(mxl <= 4)
    {
        ll times[5] = {0,0,0,0,0};
        for(int i = 0;i < n;i++)
            times[a[i]]++;
        if(times[4] >= m)
            printf("4");
        else if(times[3] >= m)
            printf("3");
        else if(times[2] >= m - times[3])
            printf("2");
        else if(times[1] >= m - times[3])
            printf("1");
        else
            printf("0");
        return 0;
    }
    sort(a,a + n,gt);
    ll ans = a[0];
    for(int i = 1;i < m;i++)
        ans &= a[i];
    printf("%lld",ans);
    return 0;
}