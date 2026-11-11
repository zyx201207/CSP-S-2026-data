#include <bits/stdc++.h>
using namespace std;
int n,tot=0,keyn[500005];
int ans=0;
long long m,a[500005],sum[500005],now=-0x3f3f3f3f3f3f3f3f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    sum[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        if(a[i]>now)
        {
            keyn[tot]=i-1;
            tot++;
            now=a[i];
        }
    }
    int j=0;
    if(tot==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=2;i<=tot;i++)
    {
        while((keyn[i]-j)*a[keyn[i]]-(sum[keyn[i]]-sum[j])>m)
        {
            j++;
        }
        ans=max(ans,keyn[i]-j);
    }
    cout<<ans;
    return 0;
}
