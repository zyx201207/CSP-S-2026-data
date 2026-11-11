#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],l,r,sum,ans,p[200005];
char c[200005];
ll find(ll x){
    ll l=1,r=n,res;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (p[mid]>=x)
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return res;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        p[i]=p[i-1]+a[i];
        sum+=a[i];
    }
    p[n+1]=sum+1;
    if (sum&1)
    {
        l=sum/2;
        r=sum/2+2;
    }
    else
    {
        l=sum/2;
        r=sum/2+1;
    }
    while (l>=1&&r<=sum)
    {
        ll bl=find(l),br=find(r);
        if (c[bl]==c[br])
        {
            ll st=min(l-p[bl-1],p[br]-r+1);
            l-=st,r+=st;
        }
        else
        {
            ll st=min(l-p[bl-1],p[br]-r+1);
            l-=st,r+=st;
            ans+=st;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
