#include<bits/stdc++.h>
using namespace std;
int n,ans=1,r=1;
long long m,a[500006],sum[500006];
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
    for(int l=1;l<=n;l++)
    {
        while(r<=n&&(r-l+1)*a[r]-(sum[r]-sum[l-1])<=m)
        {
            ans=max(ans,r-l+1);
            r++;
        }
    }
    cout<<ans;
    return 0;
}