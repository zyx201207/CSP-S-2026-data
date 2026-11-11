#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll add=0;
    for(int i=2;i<=n;++i)
    {
        int d=a[i]-a[i-1];
        sum[i]=sum[i-1]-add-d;
        add+=d;
        int l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(sum[i]-sum[mid-1]+add*(i-mid+1)<=m)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        //cerr<<i<<" "<<l<<" "<<r<<"\n";
        ans=max<ll>(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//finish at 15:17