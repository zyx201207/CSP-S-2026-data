#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,ans,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll r=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        while(r<=n&&cnt+(r-i)*(a[r]-a[r-1])<=m)cnt+=(r-i)*(a[r]-a[r-1]),r++;
        ans=max(ans,r-i);
        //cout<<i<<" "<<r<<" "<<cnt<<'\n';
        cnt=cnt-a[r-1]+a[i];
    }
    cout<<ans;
    return 0;
}
