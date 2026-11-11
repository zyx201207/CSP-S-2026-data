#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll c,t,n,d;
ll a[(ll)2e6+10];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            ll o=d,ans=0;
            for(ll i=1;i<=n;i++){
                cin>>a[i];
                if(i>1){
                    o=a[i]-a[i-1];
                }
            }
            int k=d/o;
            for(ll i=k+1;i<2*k;i++){
                ans+=n-i;
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    return 0;
}
