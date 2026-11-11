#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],sum[N],ans=INT_MIN;
bool check(int x,int i)
{
    return m>=(i-x)*a[i]-(sum[i-1]-sum[x-1]);
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;i--)
    {
        int l=1,r=i-1,pos;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,i)) r=mid-1,pos=mid;
            else l=mid+1;
        }
        ans=max(ans,(ll)i-pos+1);
    }
    cout<<ans;

    return 0;
}
