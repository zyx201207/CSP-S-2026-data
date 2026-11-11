#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+10;
ll type,t,n,d,a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>type>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[1]>=d)cout<<"0\n";
        else{
            ll num=d/(a[2]-a[1]);
            cout<<max(n-(2*num-1),0LL)<<'\n';
        }
    }
    return 0;
}
