#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],c[N],s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ans=0;
    c[1]=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1ll)-(s[i]-s[mid-1])<=m)
            {
                r=mid;
            }
            else l=mid+1;
        }
        ans=max(ans,i-r+1ll);
    }
    cout<<ans;
    return 0;
}
