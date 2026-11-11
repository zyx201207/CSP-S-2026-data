#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],ans;
ll ab(ll x)
{
    return (x>0?x:-x);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            b[j]=ab(a[j]-a[i]);
        sort(b+1,b+n+1);
        ll x=1,sum=0;
        for(x=1;x<=n;x++)
        {
            sum+=b[x];
            if(sum>m)break;
        }
        x--;
        ans=max(ans,x);
    }
    printf("%lld\n",ans);
    return 0;
}
