#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
       ll n,d;
       cin>>n>>d;
       for(int i=1;i<=n;i++)cin>>x[i];
       if(x[2]-x[1]==d){
           cout<<"0"<<'\n';
       }else{
           cout<<"2"<<'\n';
       }
    }
    return 0;
}