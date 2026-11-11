#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],x;
void dfs(ll s,ll t,ll k){
    if(s==m){
        x=max(x,t);
        return ;
    }
    if(k>n) return ;
    for(ll i=k;i<=n;i++){
        ll v=t;
        if(v==0) v+=a[i];
        else v&=a[i];
        dfs(s+1,v,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,1);
    cout<<x;
    return 0;
}
