#include<bits/stdc++.h>
using namespace std;
long long h[200005],a[200005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    long long minx=1e8;
    for(int i=1;i<=n;i++)
    {
        minx=min(minx,abs(a[i]-sum));
    }
    int x=minx+sum;
    for(int i=1;i<=n;i++)
    {
        h[i]=abs(a[i]-x);
    }
    sort(h+1,h+1+n);
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(m-h[i]>=0)
        {
            ans++;
            m-=h[i];
        }
    }
    cout<<ans;
    return 0;
}
