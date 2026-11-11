#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500015;
int n,r=1,ans = 1;
ll m,a[maxn],b[maxn];

bool ok(int l,int r)
{
    if(r>n)
        return false;
    ll tans =a[r]*(r-l+1)-b[r]+b[l-1];
    return (tans<=m);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i =1;i<=n;++i)
    {
        b[i] =b[i-1]+a[i];
    }
    for(int l =1;l<=n;++l)
    {
        while(ok(l,r+1))
        {
            ++r;
        }
        ans = max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}
