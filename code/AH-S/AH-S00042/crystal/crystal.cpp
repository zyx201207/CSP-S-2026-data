#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005,mod=998244353;
ll n,m,a[N],s[N],cnt;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    //cout<<n<<m;
    for(int i=1;i<=n;i++)
    {
        //cout<<i;
        cin>>a[i];
    }
    //cout<<3833;
    sort(a+1,a+n+1);
    for(int i=n-1;i>=1;i--)s[i]=s[i+1]+a[i];
    ll ans=0;
    for(int i=n;i>1;i--)
    {
        //cout<<i<<" ";
        if(i!=n)cnt+=a[i];
        ll l=1,r=i-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if((i-mid)*a[i]-(s[mid]-cnt)<=m)
            {
                ans=max(i-mid+1,ans);
                r=mid-1;
            }
            else l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
