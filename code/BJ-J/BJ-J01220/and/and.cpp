#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans,n,m;
ll a[200005],b[200005];
void dfs(ll deep,ll num,ll cnt){
    b[deep]=cnt;
    if(deep==m){
        ll tem=b[1];
        for(ll i=2;i<=m;i++){
            tem&=b[i];
            //cout<<b[i]<<' ';
        }
        //cout<<'\n';
        ans=max(ans,tem);
        return;
    }
    for(ll i=num+1;i<=n;i++){
        dfs(deep+1,i,a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++){
        dfs(1,i,a[i]);
    }
    cout<<ans;
    return 0;
}