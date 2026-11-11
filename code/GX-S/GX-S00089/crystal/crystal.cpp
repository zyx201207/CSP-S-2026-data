#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
int n,m;
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        int ssum=sum[i]-sum[i-x];
        if(x*a[i]-ssum<=m) return true;
    }
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    sum[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
