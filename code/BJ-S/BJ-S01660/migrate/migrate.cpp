#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e6+10;
ll c,t,n,a[MAXN],low[MAXN],hig[MAXN],d,ans;
ll find1(ll l,ll r,ll x){
    ll mid,ans;
    while (l<=r){
        mid=(l+r)/2;
        if (a[mid]>=x){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
ll find2(ll l,ll r,ll x){
    ll mid,ans;
    while (l<=r){
        mid=(l+r)/2;
        if (a[mid]<=x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
ll cal(ll l,ll r,ll x){
    ll L=l,R=r,ansl=-1,ansr=-1,mid;
    while (L<=R){
        mid=(L+R)/2;
        if (low[mid]==x){
            ansr=mid;
            L=mid+1;
        }
        else if (low[mid]>x) R=mid-1;
        else L=mid+1;
    }
    while (l<=r){
        mid=(l+r)/2;
        if (low[mid]==x){
            ansl=mid;
            r=mid-1;
        }
        else if (low[mid]>x) r=mid-1;
        else l=mid+1;
    }
    if (ansl==-1 && ansr==-1) return 0;
    return ansr-ansl+1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while (t--){
        ans=0;
        cin>>n>>d;
        for (ll i=1;i<=n;i++) cin>>a[i];
        for (ll i=1;i<=n;i++){
            low[i]=find1(1,i,a[i]-d);
            hig[i]=find2(i,n,a[i]+d);
        }
        for (ll i=1;i<=n;i++){
            ll k=hig[i]-1;
            ans+=cal(i,n,k);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
