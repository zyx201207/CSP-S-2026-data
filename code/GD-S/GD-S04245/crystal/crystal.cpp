#include<bits/stdc++.h>
using namespace std;
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(int i=s;i>=t;--i)
#define endl '\n'
#define pb push_back
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=5e5+10;

ll a[N];
void __solve(){
    int n;cin>>n;
    ll m;cin>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int p=1;ll s=0;
    int ans=0;
    rep(i,1,n){
        s+=(a[i]-a[i-1])*(i-p);
        while(p<i&&s>m){
            s-=a[i]-a[p];
            ++p;
        }
        ans=max(ans,i-p+1);
    }
    cout<<ans<<endl;
}
int main(){
#ifndef DEBUG
    file(crystal)
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) __solve();
    return 0;
}