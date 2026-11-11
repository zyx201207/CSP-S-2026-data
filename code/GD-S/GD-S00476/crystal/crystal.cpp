#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,mid,a[510000],q[510000],mx;
bool check(long long x,long long y)
{
    long long s=q[y]-q[x-1],z=a[y]*(y-x+1);
    if(z-s<=m)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        q[i]=q[i-1]+a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        l=1;
        r=i;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid,i)==true)
            {
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        mx=max(mx,i-r);
    }
    cout<<mx;
    return 0;
}
