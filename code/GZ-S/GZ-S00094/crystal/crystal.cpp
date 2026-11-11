//GZ-S00094 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int mod=1e9+7;
ll qp(ll x,ll y){ll res=0;while(y){if(y&1) res=res*x%mod;x=x*x%mod;y/=2;}return res%mod;}
ll n,m,a[500005],pr[500005],ans;
bool ck(ll x){
    for(int i=x;i<=n;i++)
        if(a[i]*x-pr[i]+pr[i-x]<=m)
                return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
    ll l=0,r=n+1;
    while(l+1<r){
        ll mid=(l+r)/2;
        if(ck(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}
