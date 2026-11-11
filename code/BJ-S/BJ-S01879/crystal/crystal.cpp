#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int q[500005];
bool check(int num)
{
    int i;
    for(i=num;i<=n;i++)
    {
        if(a[i]*(num-1)-q[i-1]+q[i-num]<=m)
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        q[i]=q[i-1]+a[i];
    }
    int l=1,r=n;
    int ans=1;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
