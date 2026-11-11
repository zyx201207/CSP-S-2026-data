#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
ll a[MAXN],pre[MAXN],erp[MAXN];
char c[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,all=0;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+a[i];
        cin>>c[i];
        all+=a[i];
    }
    for(ll i=0;i<n;i++)
    {
        erp[i+1]=all-pre[i];
    }
    ll sum=0,l=1,r=n,ans=0;
    all>>=1;
    while(!(pre[l]>all&&erp[r]>all))
    {
        ans-=sum;
        sum=min(pre[l],erp[r]);
        if(c[l]==c[r])
        {
            if(pre[l]<=erp[r])
            {
                l++;
            }
            else
            {
                r--;
            }
            continue;
        }
        if(pre[l]<=erp[r])
        {
            ans+=pre[l];
            l++;
        }
        else
        {
            ans+=erp[r];
            r--;
        }
    }
    if(c[l]!=c[r])
    {
        ans+=all-sum;
    }
    printf("%lld",ans);
    return 0;
}
