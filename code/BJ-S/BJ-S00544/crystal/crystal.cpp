#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],c[500005],sc[500005];
bool chk(int x)
{
    x--;
    int res=0;
    for(int i=1;i<=x;i++)
    {
        res+=c[i]*i;
    }
    if(res<=m) return true;
    for(int i=2;i+x-1<=n;i++)
    {
        int j=i+x-1;
        res-=sc[j-1]-sc[i-2];
        res+=c[j]*x;
        if(res<=m) return true;
    }
    return false;
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
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        c[i]=a[i+1]-a[i];
        sc[i]=sc[i-1]+c[i];
    }

    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(chk(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
