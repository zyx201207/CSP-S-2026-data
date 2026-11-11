#include <bits/stdc++.h>
using namespace std;
long long a[500500],d[500500];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        d[i]=(long long)(d[i-1]+a[i]);
        //cout<<d[i]<<" ";
    }
    long long ans=0;
    for (long long i=1;i<=n;i++)
    {
        //cout<<endl<<a[i]*i*1ll-d[i]<<" ";
        //if (a[i]*i*1ll-d[i]<=m) ans=i;
        long long l=1,r=i,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if (a[i]*(i-mid+1)*1ll-(d[i]-d[mid-1])>m) l=mid+1;
            else r=mid-1;
        }
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
