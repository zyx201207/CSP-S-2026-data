#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200050],m;
vector<ll> h[33];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        //pos j
        for(int j=30;j;j--){
            if((a[i]>>(j))&1){
                h[j+1].push_back(a[i]);
                break;
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int j=30;~j;j--) sort(h[j].begin(),h[j].end(),cmp);
    int cnt=0,ok=0;
    ll ans=(1ll<<62)-1;
    for(;cnt<m;){
        for(int j=30;j;j--){
            if(signed(h[j].size())>=m){
                ok++;
                for(ll k:h[j]){
                    if(cnt==m) break;
                    ans&=k;
                    cnt++;
                }
            }
        }
        if(!ok) break;
        if(cnt==m) break;
    }
    if(ans==(1ll<<62)-1) for(int i=1;i<=m;i++) ans&=a[i];
    cout<<ans<<'\n';
    return 0;
}