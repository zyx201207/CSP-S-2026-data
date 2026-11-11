#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500003],minx=1000000000001,maxn=-1000000000001,ans;
bool check(long long x)
{
    long long cnt=0;
    for(long long i=1;i<=n;i++)
    {
        if(a[i]<x)
        {
            cnt+=x-a[i];
        }
    }
    if(cnt<=m)return 1;
    else return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        minx=min(minx,a[i]);
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    long long l=minx,r=maxn,mid=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        if(a[i]<=mid)ans++;
        else break;
    }
    cout<<ans;
    return 0;
}