#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[220000],maxx=-123123,startt;
void dfs(ll ans,ll pos,ll tmp){
    if(tmp==m){
        maxx=max(maxx,ans);
        return ;
    }
    if(pos>n)return ;
    for(ll i=pos;i<n;i++){
        dfs(ans&a[i],i+1,tmp+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cin>>n>>m;
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    while(a[startt]==0){
        startt++;
    }
    if(n-startt<m){
        cout<<0;
        return 0;
    }
    for(ll i=startt;i<n;i++){
        ll tmp=a[i];
        dfs(a[i],i+1,1);
    }
    cout<<maxx;
    return 0;
}
