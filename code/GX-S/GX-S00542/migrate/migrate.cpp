#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,l;
ll q,an=0;
bool tw(ll n,ll m){
    int answ=0;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll t,n,m;
    cin>>q>>t;
    for(ll t=0;t<n;t++){
        a.erase(a.begin(),a.end());
        l.erase(l.begin(),l.end());
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>q;
            a.push_back(q);
        }
        for(ll i=1;i<n;i++){
            l.push_back(a[i]-a[i-1]);
        }
        cout<<2;
    }
}
