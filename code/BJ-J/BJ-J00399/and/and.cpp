#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[6400000][2],sum[6400000][2],a[200010],cnt=0;
void add(ll s){
    ll x=0;
    for(ll i=31;i>=0;i--){
        if(!t[x][(s>>i)&1])t[x][(s>>i)&1]=++cnt;
        sum[x][(s>>i)&1]++;x=t[x][(s>>i)&1];
    }
}
ll ask(ll m){
    ll ans=0,x=0;
    for(ll i=31;i>=0;i--){
        if(sum[x][1]>=m)ans+=(1ll<<i),x=t[x][1];
        else x=t[x][0];
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)add(a[i]);
    cout<<ask(m);
    return 0;
}