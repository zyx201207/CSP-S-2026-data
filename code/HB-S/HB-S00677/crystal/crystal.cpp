#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+5,mod=998244353;
const ll inf=1e18;
ll n,m,a[N],pre[N],ans;
ll calc(ll i,ll j){
    return 1ll*(i-j+1)*a[i]-pre[i]+pre[j-1];
}
/*
rp++.
*/
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    fastio
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(ll i=1,j=1;i<=n;i++){
        while(calc(i,j)>m) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
g++ crystal.cpp -o a
./a

*/