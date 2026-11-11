#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll n,m;
ll a[1000010];
ll cnt[600010];
ll x[1000010];
ll p[600010];
void try_48(){
    for(ll i=1;i<=n;i++){
        memset(x,0,sizeof(x));
        memset(p,0,sizeof(p));
        ll r=0;
        for(ll j=i;j<=n;j++){
            if(p[a[j]]!=0 && p[a[j]]<=r && x[p[a[j]]]==a[j])r=p[a[j]];
            else{
                r++;
                p[a[j]]=r;
                x[r]=a[j];
            }
        }
        for(ll j=1;j<=r;j++){
            cnt[x[j]]++;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000)try_48();
    return 0;
}
//5 3
//1 2 1 3 2
