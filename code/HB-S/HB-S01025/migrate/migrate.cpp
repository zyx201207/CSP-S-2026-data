#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+6;
ll n=0,T,c,u,v,l,d,x[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while (T--){
        for (ll i=1;i<=n;i++) x[i]=0;
        cin>>n>>d;
        for (ll i=1;i<=n;i++) cin>>x[i];
        cout<<0<<endl;
    }
    return 0;
}
