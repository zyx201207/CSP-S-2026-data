#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],f[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,i;
    ll m;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
        f[i]=f[i-1]+a[i];
    int ans=0;
    for(i=1;i<=n;i++)
    {
        int l=1,r=i,cnt=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            ll ji=(ll)a[i]*(i-mid+1);
            if((f[i]-f[mid-1])>=ji-m)
            {
                cnt=max(cnt,i-mid+1);
                r=mid-1;
            }
            else
                l=mid+1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
