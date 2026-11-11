#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
ll c,n;
void solve(){
    cin>>c>>n;
    while(n--){
        ll d,t;
        cin>>d>>t;
        cout<<d-t-1<<"\n";
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll _=1;
    while(_--)solve();
    return 0;
}

