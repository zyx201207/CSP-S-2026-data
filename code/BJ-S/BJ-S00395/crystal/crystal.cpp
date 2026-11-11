#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Minn=-1e12-5;
const ll Maxn=1e12+5;
ll n,m,a[500005];
ll ans;
ll dis[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll maxn=Minn,minn=Maxn;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dis[i]=maxn-a[i];
    }

    for(ll i=maxn;i>=minn;i--){
        ll sum=0,cnt=0;
        ll l=1,r=n;
        while(l<r){
            ll mid=(l+r)/2;
            if(a[mid]>=i){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        for(ll j=l;j>=1;j--){
            if(dis[j]-maxn+i<0) continue;
            if(sum+dis[j]-maxn+i>m){
                break;
            }
            sum=sum+dis[j]-maxn+i;
            cnt++;
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
