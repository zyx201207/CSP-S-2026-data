#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
const int N=5e5+12;
ll n,m;
ll a[N];
ll hr[N];
ll mic(ll i,ll m){
    ll ans=0;
    ll ij=i;
    ll r=hr[i]-hr[ij];
    while(m-r>=0&&i>0){
        r=hr[i]-hr[ij];
        m-=r;
        i--;
        ans++;
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    f(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=n-1;i>=1;i--){
        hr[i]=hr[i+1]+a[i+1]-a[i];
    }
    f(i,1,n) cout<<mic(i,m)<<" ";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
