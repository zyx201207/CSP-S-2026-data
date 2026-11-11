#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500010],b[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1]) continue;
        long long l=0,r=i,mid;
        while(l+1<r)
        {
            mid=(l+r)/2;
            if(1ll*(i-mid+1)*a[i]-(b[i]-b[mid-1])<=m) r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans;
}