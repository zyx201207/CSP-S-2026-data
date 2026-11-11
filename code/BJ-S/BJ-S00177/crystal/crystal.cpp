#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N];
int n;
long long m;
bool check(int k)
{
    k-=1;
    for(int i=1;i<=n;i++)
    {
        if(i+k>n)
        {
            break;
        }
        long long t=a[i+k]*k-(sum[i+k]-sum[i-1]);
        if(t<=m)
            return 1;
    }
    return 0;
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
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
