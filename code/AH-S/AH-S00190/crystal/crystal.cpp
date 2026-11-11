#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],ans;
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=1,s=0;
    while(r<=n){
        while(r<=n&&(r-l+1)*a[r]-(s+a[r])<=m){
            s+=a[r++];
        }
        ans=max(ans,r-l);
        s-=a[l++];
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
