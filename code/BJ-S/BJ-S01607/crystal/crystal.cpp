#include<bits/stdc++.h>
#define ll long long
#define N 1919810
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll a[N],s[N];
ll n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    qck;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ans=0;
    for(ll l=1,r=1;r<=n;){
        while(r<=n){
            r++;
            if((r-l)*a[r]-(s[r-1]-s[l-1])>m) break;
            ans=max(ans,r-l+1);
        }
        while(l<=r){
            if((r-l)*a[r]-(s[r-1]-s[l-1])<=m) break;
            l++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}