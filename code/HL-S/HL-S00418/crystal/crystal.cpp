#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],mx=-1,sum = 0;
bool cmp(int x,int y)
{
    return x >= y;
}
bool chenk(ll x)
{
    ll ans = 0;
    sum = 0;
    for(register int i=1;i<=n;i++)
    {
        if(a[i]>x)
        {
            continue;
        }else{
            ans += (x - a[i]);
            if(ans > m)return false;
            sum ++;
        }
    }
    return true;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    ll l=a[n],r=a[1];
    while(l <= r)
    {
        ll mid = (l+r)/2;
        if(chenk(mid)){
                l=mid+1;
        }else{
                r = mid-1;
        }
        mx = max(mx,sum);
    }
    printf("%lld",mx);
    return 0;
}
