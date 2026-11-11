#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
bool check(int x)
{
    ll sum=0;
    for(int i=1;i<=x;i++)
    {
        sum+=(a[x]-a[i]);
    }
    return (sum<=m);
}
int bins(int l,int r)
{
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=bins(1,n);
    cout<<ans;
    return 0;
}
