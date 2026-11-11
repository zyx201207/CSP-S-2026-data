#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010]={},cha[500010]={};
long long ans=-1e18;
int ci(int er)
{
    long long c=0,g=0,jans=1e18,jl=0,jr=0;
    for(int i=1;i<=n;i++)
    {
        c+=cha[i];g++;
        if(g==er)
        {
            if(c<jans)
            {
                jans=min(c,jans);
                jl=i-er+1;
                jr=i;
            }
            c-=cha[i-er+1];
        }
    }
    int h=0;
    for(int i=jl;i<=jr;i++)
    {
        h+=a[jr]-a[i];
    }
    return h;
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
        cha[i]=a[i]-a[i-1];
    }
    long long l=1,r=n;
    long long mid=0;
    while(l<=r)
    {
        mid=(l+r+1)/2;
        if(ci(mid)>m)
        {
            r=mid-1;
        }
        else
        {
            ans=max(mid,ans);
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
