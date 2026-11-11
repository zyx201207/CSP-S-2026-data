#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
typedef long long ll;
ll d;
const int N=2e6+5;
ll x[N];
bool chk1(){
    ll a=x[2]-x[1];
    for(int i=2;i<n;i++)if(x[i+1]-x[i]!=a)return 0;
    return 1;
}
void taskA(){//dengcha
    ll a=x[2]-x[1];
    ll k=d/a;
    if(k<=1)cout<<"0\n";
    else cout<<max(0ll,n-2*k+1)<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(chk1())taskA();
    }
    return 0;
}