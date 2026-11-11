#include<bits/stdc++.h>
#define int ll
#define all(op) op.begin(),op.end()
#define all1(op) op.begin()+1,op.end()
using namespace std;
using ll=long long;
using db=double;
using ldb=long double;
using i128=__int128_t;
const int inf=1e9+7;
const ll INF=1e18+7,M=1e12+7;
const db eps=1e-9;
void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(all1(a));
    vector<pair<int,int>> lp;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        if(a[i]!=a[i-1])lp.push_back({i,1});
        else lp.back().second++;
    }
    auto check=[&](int x,int y)->bool {
        // cerr<<x<<" "<<y<<"---------------------\n";
        if((y-x)*a[y]-(sum[y-1]-sum[x-1])<=m)return 1;
        return 0;
    };
    int ans=0;
    for(auto u:lp){
        // cerr<<u.first<<" "<<u.second<<"--------------\n";
        int l=1,r=u.first,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid,u.first))r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,u.first-l+u.second);
        // cerr<<u.first<<"---------->"<<l<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // freopen("crystal4.in","r",stdin);
    // freopen("code.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}
/*
15:00
*/