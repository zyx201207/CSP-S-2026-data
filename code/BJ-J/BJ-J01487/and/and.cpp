#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005],p[200005];
map<ll,bool>mp;
ll n,m;
ll ans;
void dfs(ll pos){
    if(pos==m+1){
        ll now=p[1];
        for(ll i=2;i<=m;i++){
            now&=p[i];
        }
        ans=max(ans,now);
        return ;
    }
    for(ll i=pos;i<=n;i++){
        if(!mp[a[i]]){
            mp[a[i]]=true;
            p[pos]=a[i];
            dfs(pos+1);
            mp[a[i]]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll mx=0;
    bool flag=true;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1)flag=false;
        mx=max(mx,a[i]);
    }
    if(n<=2000){
        dfs(1ll);
        cout<<ans<<'\n';
    }else{
        if(flag){
            cout<<(a[n] & a[n-1])<<'\n';
        }else cout<<mx<<'\n';
    }
    return 0;
}