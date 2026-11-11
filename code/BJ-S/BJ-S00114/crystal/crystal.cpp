#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],sum[N];
bool ch(int x)
{
    for(int i=x;i<=n;i++)
    {
        if(a[i]*x-(sum[i]-sum[i-x])<=m) return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n,mid,ans=1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(ch(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}