#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ans,l,r,k;
long long m,sum[N],a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
    }
    l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid==l) break;
        if(sum[mid]<=m)
        {
            l=mid;
            k=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    l=1;
    ans=k-l+1;
    for(int i=k+1;i<=n;i++)
    {
        while(sum[i]-sum[l-1]-(a[i]-a[l-1])*(l-1)>m)
        {
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}