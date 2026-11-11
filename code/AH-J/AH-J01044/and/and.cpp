#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 100;
ll a[N],vst[N];
bool cmp(ll x,ll y){return x > y;}
ll n,m,ans;
void dfs(ll x,ll cnt,ll sum){
    if(x == n+1){
        if(cnt == m)ans = max(ans,sum);
        return;
    }
    dfs(x+1,cnt,sum);
    dfs(x+1,cnt+1,(sum&a[x]));
}
void solveBF(){
    dfs(1,0,0b1111111111111111111111111111111);
    cout<<ans<<'\n';
}
void solvemn(){
    ll ans = 0b1111111111111111111111111111111;
    for(ll i=1;i<=m;i++){
        ll cnt = 0,x;
        for(ll j=1;j<=n;j++){
            if(vst[j])continue;
            if((ans & a[j]) > cnt){
                cnt = (ans & a[j]);
                x = j;
            }
        }
        ans = cnt;
        vst[x] = 1;
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    if(n <= 20){
        solveBF();
        return 0;
    }
    if(n <= 2000){
        solvemn();
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m]<<'\n';
    return 0;
}