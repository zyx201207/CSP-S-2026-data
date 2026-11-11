#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    sort(a+1,a+n+1);

    long long r=1,sum=a[1];
    for(long long l=1;l<=n;l++)
    {
        while(r<=n&&((a[r]*(r-l+1))-sum)<=m)
        {
            ans=max(ans,r-l+1);
            r++;
            sum+=a[r];
        }
        sum-=a[l];
    }
    cout<<ans;
    return 0;
}
