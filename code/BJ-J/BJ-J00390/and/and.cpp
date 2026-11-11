#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2010;
ll n,m;
ll a[maxn];
ll ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
 ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    ll maxmax=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        maxmax=max(maxmax,a[i]);
    }
    if(m==1){
        cout<<maxmax;
        return 0;
    }
    ll pre;
    for(ll i=1;i<=n;i++){
        pre=a[i+1];
        for(ll j=i+1;j<=n;j++){
            if(i+1+m>n)continue;
            ll cnt=0;
            pre&=a[j];
            cnt++;
            if(cnt==m)continue;
        }
        ans=max(ans,pre);
    }
    cout<<ans;
    return 0;
}
