#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans,m,sumb[500005];
bool check(int mid)
{
    long long sum=1e18,sum1;
    for(int i=mid;i<=n;i++)
    {
        long long x=0;
        for(int j=i-mid+1;j<=i;j++)
        {
            x+=a[i]-a[j];
        }
        sum=min(x,sum);
    }
    //cout<<sum<<"\n";
    return sum<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sumb[i]=sumb[i-1]+a[i]-a[i-1];
    }
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        //cout<<mid<< " ";
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}
