#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum,cnt,ans,ccnt;
signed main()
{

   freopen("crystal.in","read",stdin);
    freopen("crystal.out","write",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int t=n;
    while(a[t]-a[1]>m)
    {
        t--;
    }
    int k=1;
    while(a[n]-a[k]>m)
    {
        k++;
    }
    for(int i=t;i>=1;i--)
    {
        if(sum+a[t]-a[i]>m)break;
         else sum+=a[t]-a[i],cnt++;


    }
    for(int i=k;i<=n;i++)
    {
        if(sum+a[i]-a[k]>m)break;
         else sum+=a[i]-a[k],ccnt++;


    }
    if(ccnt<cnt)
    cout<<cnt;
    else cout<<ccnt;
}
