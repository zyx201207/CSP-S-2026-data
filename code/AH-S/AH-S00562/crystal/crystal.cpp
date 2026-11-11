#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e6+5;
ll n,m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll cnt=0,x=m,ans=1;
    for(ll i=0;i<n;i++){
        for(ll j=a[i];j<a[i+1];j++){
            if(x-ans<0){
                cout<<cnt+1;
                return 0;
            }else{
                x-=ans;
            }
        }
        cnt++;
        ans++;
    }
    return 0;
}
