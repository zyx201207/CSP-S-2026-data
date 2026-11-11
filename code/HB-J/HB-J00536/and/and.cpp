#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n<=20){
        ll ans=0;
        for(ll i=1;i<=n;i++) cin>>a[i];
        do{
            ll q=2e30-1;
            for(ll i=1;i<=m;i++){
                q&=a[i];
            }
            ans=max(ans,q);
        }while(next_permutation(a+1,a+1+n));
        cout<<ans;
        return 0;
    }
    if(m==1){
        ll x,ans=0;
        for(ll i=1;i<=n;i++) cin>>x,ans=max(ans,x);
        cout<<ans;
        return 0;
    }
    if(m==n){
        ll x,ans;
        cin>>x;
        ans=x;
        for(ll i=2;i<=n;i++) cin>>x,ans&=x;
        cout<<ans;
        return 0;
    }
    if(m==2){
        ll ans=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            for(ll j=1;j<i;j++){
                ans=max(a[i]&a[j],ans);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        ll ans=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++){
            ll q=2e30-1;
            for(ll j=1;j<=n;j++){
                if(j==i) continue;
                q&=a[j];
            }
            ans=max(ans,q);
        }
        cout<<ans;
        return 0;
    }
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<a[m];
    return 0;
}
