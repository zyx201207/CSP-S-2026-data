#define DEF 500005
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int ans=1,n;
ll a[DEF],delta[DEF],m,p[DEF];
int bisect(int l,int r)
{
    int _l=l,_r=r,mid;
    while(_l<_r)
    {
        mid=(_l+_r)>>1;
        if(p[mid]-p[r+1]-delta[r]*(r-mid+1)>m)
            _l=mid+1;
        else
            _r=mid;
    }
    return r-_l+1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<n;++i)
        delta[i]=a[n]-a[i];
    for(int i=n-1;i>0;--i)
        p[i]=delta[i]+p[i+1];
    for(int i=n;i>0;--i)
    {
        int res=bisect(1,i);
        ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}
