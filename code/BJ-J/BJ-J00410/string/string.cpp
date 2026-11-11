#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
struct node{
    ll len;
    char c;
};
ll n;
ll ans;
node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll l=1,r=n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
    }
    while(l<r){
        ll mlen=min(a[l].len,a[r].len);
        if(a[l].c!=a[r].c){
            ans+=mlen;
        }
        a[l].len-=mlen,a[r].len-=mlen;
        if(a[l].len<=0){
            l++;
        }
        if(a[r].len<=0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
