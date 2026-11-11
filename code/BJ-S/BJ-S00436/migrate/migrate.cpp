#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll c,T;
    cin>>c>>T;
    if(c){
        while(T--){
            ll n,d;
            cin>>n>>d;
            for(ll i=1;i<=n;i++){
                cin>>x[i];
            }
            ll xd=x[2]-x[1];
            ll ans=d/xd;
            if(ans==0 || ans==1) cout<<0<<endl;
            else{
                ll sum=0;
                for(ll i=3;i<n;i++){
                    if(i>ans && i-ans<ans && (i*xd-d-1>d || i==3)){
                        //cout<<i%ans*xd<<endl;
                        sum+=(n-i)*1ll;
                    }
                }
                cout<<sum<<endl;
            }
        }
        return 0;
    }
    return 0;
}
