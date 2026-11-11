#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[500005],a[500005],sum[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    sum[0]=0;
    for(int i=2;i<=n;i++)
    {
        s[i-1]=a[i]-a[i-1];
        sum[i-1]=sum[i-2]+s[i-1];
    }
    int now=0,num=0,maxn=0;
    for(int i=1;i<n;i++)
    {
        now++;
        num+=s[i]*now;
        while(num>m)
        {
            now--;
            num-=sum[i]-sum[i-now-1];
        }
        maxn=max(maxn,now);
    }
    cout<<maxn+1;
}