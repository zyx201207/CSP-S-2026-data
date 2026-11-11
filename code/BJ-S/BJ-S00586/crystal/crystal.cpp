#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[500005],s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        ll l=1,r=i;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            __int128 tmp=(i-mid)*a[i];
            tmp-=s[i-1]-s[mid-1];
            if(tmp<=m)r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
