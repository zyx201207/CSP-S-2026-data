#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll a[400010];
bool f[400010];
ll ans=0;
void dfs(ll cur,ll sum){
    if(cur>n){
        if(sum==m){
            ll x=2147483647;
            for(ll i=1;i<=n;i++){
                if(f[i])x&=a[i];
            }
            ans=max(ans,x);
        }
        return;
    }
    for(ll i=0;i<=1;i++){
        f[cur]=i;
        dfs(cur+1,sum+f[cur]);
    }
}
ll try_25(){
    dfs(1,0);
    return ans;
}
ll try_50(){
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll ma=0,an=2147483647;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        an&=a[i];
    }
    if(n<=20)cout<<try_25();
    else if(m==1)cout<<ma;
    else if(m==n)cout<<an;
    else if(m==2)cout<<try_50();
    return 0;
}
