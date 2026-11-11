#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll ma=max(ma,a[i]);
    }
    ll ans=0;
    sort(a+1,a+1+n);

    for(int i=n;i>=1;i--){

        if(a[i]<a[i-1]){
                cout<<n;
        return 0;

        }else{
            ll c=a[i-1]-a[i];
            //cout<<c<<"\n";

            if(m>c){
                m=m-c;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
