#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
ll l[200005];
ll shu[35];
ll in;
ll n,m;
bool cmp(ll x,ll y){
    for(ll k=in;k>=1;k--){
        ll bx=x&(1<<(k-1));
        if(bx>0) bx=1;
        ll by=y&(1<<(k-1));
        if(by>0) by=1;
        if(bx==by){

        }else{
            return bx>by;
        }
    }
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>l[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll k=30;k>=1;k--){
            ll b=l[i]&(1<<(k-1));
            if(b>0){
                shu[k]++;
                break;
            }
        }
    }
    ll ina=1;
    for(ll i=32;i>=1;i--){
        if(shu[i]>=m){
            in=i;
            break;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll k=30;k>=1;k--){
            ll b=l[i]&(1<<(k-1));
            if(b>0&&k==in){
                a[ina++]=l[i];
                break;
            }
        }
    }
    sort(a+1,a+ina+1,cmp);
    ll sum=a[1];
    for(ll i=2;i<=m;i++){
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
