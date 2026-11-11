#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ffor(i,j,k) for(ll i=(j);i<=(k);i++)
#define rfor(i,j,k) for(ll i=(k);i>=(j);i--)
#define vec vector
#define pq priority_queue
#define sta stack
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pob pop_back
#define debug(x) cout<<"DEBUG:"<<x<<endl;
#define __ " "
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vec<ll>a(n+1,0),sum(n+1,0);
    sum[0] = 0;
    ffor(i,1,n){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    ffor(i,1,n)sum[i] = sum[i-1]+a[i];
    ll ans = 1;
    ffor(i,2,n){
        ll l=1,r=i;
        while(l<r){
            int mid = (l+r)>>1;
            if(a[i] * (ll)(i-mid+1) - sum[i]+sum[mid-1] <= m ){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans<<endl;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}