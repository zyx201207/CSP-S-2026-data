#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int l,r;
int a[N],f[N];
int minn;
int now;
bool check(int x)
{
    if(a[now]-a[x+1]-f[x]*(x-now+1)<=m)return 1;
    return 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    for(int i=1;i<=n;i++)a[i]-=minn-1;
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)a[i]=a[i]-a[i-1];
    for(int i=n;i>=1;i--)a[i]=a[i]+a[i+1];
    for(int i=1;i<=n;i++)f[i]=a[i];
    for(int i=n;i>=1;i--)a[i]=a[i]+a[i+1];
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        now=l=i;r=n;
        int t=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))l=mid+1,t=mid;
            else r=mid-1;
        }
        ans=max(ans,t-i+1);
    }
    cout<<ans;
    return 0;
}