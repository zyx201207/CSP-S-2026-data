#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll n,m,a[maxn],sum[maxn],len,res,ans,pos;
inline bool cmp(ll x,ll y){return x<y;}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        ll l=1,r=i,res;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
