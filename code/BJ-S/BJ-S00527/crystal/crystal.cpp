#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500011],f[500011],n,m;
bool check(int t,int x)
{
    if(a[t]*(t-x)-(f[t-1]-f[x-1])<=m)return 0;
    return 1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        int l=1,r=i-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(i,mid))
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        //cout<<i<<" "<<l<<" "<<r<<"\n";
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
