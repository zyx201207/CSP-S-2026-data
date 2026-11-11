#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    ll cn=0;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        if(a[i]!=a[i-1]&&i!=1){
            cn++;
            c[cn]=i-1;
        }
    }
    cn++;
    ll mid=c[cn/2+1];
    // cout << mid ;
    ll ans=0;
    for(ll i=mid;i>=1;i--){
        if(!m){
            break;
        }
        ll cnt=a[mid]-a[i];
        m-=cnt;
        ans++;
    }
    cout << ans ;
    return 0;
}
//Oct31==Dec25?
