#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll sum[N];
int n,m;
ll find(int id)
{
    int ans=id;
    int l=1,r=id;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        ll total=sum[id]-sum[mid-1];
        __int128 need=(__int128)a[id]*(id-mid+1)-total;
        if(need>m)
        {
            l=mid+1;
        }
        else
        {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=find(i);
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}