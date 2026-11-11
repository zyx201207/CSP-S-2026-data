#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
__int128 sum[500005];
bool check(int x)
{
    for(int i=x;i<=n;i++)
    {
        __int128 y=a[i]*x;
        __int128 z=sum[i]-sum[i-x-1];
        if(y-z<=m)
        return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
