#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;
int n;
ll m;
ll a[N],sum[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i-1;
        int cnt=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(((i-mid)*a[i]-sum[i-1]+sum[mid-1])<=m)
            {
                cnt=max(i-mid,cnt);
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,cnt+1);
    }
    cout<<ans;
    return 0;
}
