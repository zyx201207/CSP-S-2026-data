#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=5e5+10;
int n;
long long m,a[mx],sum[mx];
bool check(int x)
{
    for(int i=1;i+x-1<=n;i++)
    {
        long long cst=x*a[i+x-1]-sum[i+x-1]+sum[i-1];
        if(cst<=m) return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    int ans=1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid;
    }
    cout<<ans;
    return 0;
}