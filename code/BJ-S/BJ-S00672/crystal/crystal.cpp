#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans,cnt,mus;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        if((i-1)*a[i]-sum[i-1]>m)break;
        cnt=(i-1)*a[i]-sum[i-1];
        ans++;
    }
    for(int i=2;i<=n;i++)
    {
        mus=max(mus,ans-i+2);
        while(ans<=n&&cnt<m)
        {
            ans++;
            cnt=(ans-i)*a[ans]-sum[ans-1]+sum[i-1];
        }
        ans--;
        cnt=(ans-i)*a[ans]-sum[ans]+sum[i-1];
        if(ans==n)
        {
            mus=max(mus,ans-i+1);
            break;
        }
    }
    cout<<mus;
    return 0;
}
