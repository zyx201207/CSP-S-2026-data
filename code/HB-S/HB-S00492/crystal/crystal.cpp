#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N],sum[N],down[N],m,n,cnt,q,ans;
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        long long dx=1ll*a[i]*x-sum[i]+sum[i-x-1];
        if(dx<=q) return 1;
    }
    return 0;
}
int qfind()
{
    long long l=1,r=n,mid;
    while(l<=r)
    {
        mid=(r-l)/2+l;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    cout<<qfind();
    return 0;
}
