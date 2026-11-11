#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[1000000],ans;
void dfs(ll x,ll ms,ll s){
    if(ms==m){
        ans=max(ans,s);
        return;
    }
    if(x>n)return;
    dfs(x+1,ms,s);
    dfs(x+1,ms+1,s&a[x]);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        ll x=a[1];
        for(ll i=2;i<=n;i++)x&=a[i];
        cout<<x;
        return 0;
    }else{
        if(m==1){
            ll ans=0,s=0x3f3f3f3f3f3f3f;
            for(ll i=1;i<=n;i++)ans=max(ans,s&a[i]);
            cout<<ans;
        }
        else if(n<=20){
           dfs(1,0,0x3f3f3f3f3f3f3f);
           cout<<ans;
        }
        else cout<<pow(2,n)-1;
    }

    return 0;
}
