#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
bool check(long long x)
{
    long long res=1e18,temp=0;
    for(long long i=1;i<=x-1;i++) temp+=a[x]-a[i];
    res=temp;
    for(long long i=2;i<=n-x+1;i++)
    {
        temp=temp+(x-1)*(a[i+x-1]-a[i+x-2])-a[i+x-2]+a[i-1];
        res=min(res,temp);
    }
    return res<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=n,ans=1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
