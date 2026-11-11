#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],sum[500005],m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int l,r,mid,ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        l=1,r=i;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
            {
                r=mid;
            }else
            {
                l=mid+1;
            }
        }
        //cout<<'('<<i<<' '<<r<<')';
        ans=max(ans,i-r+1);
    }
    cout<<ans;
}
