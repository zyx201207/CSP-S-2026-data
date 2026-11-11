#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m;
ll a[N],s[N];
ll ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
        if(i*a[i]-s[i]<=m){
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
