#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m,sum[500005];
bool check(int d)
{
    for(int i=d;i<=n;i++)
    {
        if(a[i]*(d-1)-(sum[i-1]-sum[i-d])<=m)return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}

/*
我常常追忆过去啦啦啦嘟嘟。

我是锣鼓 ExCh_dd2014_Gcdunk

啦啦啦啦啦啦啦

Sin city's cold and empty.

No one's around to judge me.

I can't see clearly when you're gone.
*/
