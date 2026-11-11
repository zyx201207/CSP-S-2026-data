#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],ans;
ll hb(ll x,ll y,ll c){
 ll s=0;
 while(x>=0&&y){
    y--;
    x-=(a[c]-a[y]);
    s++;
 }
 return s;
 }
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(ll i=1;i<=n;i++){
        ans=max(hb(m,i,i),ans);
    }
    cout<<ans;
    return 0 ;
}
