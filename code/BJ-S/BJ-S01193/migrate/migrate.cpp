#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll x[N];
int main(){
    ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
        ll n,d;
        cin>>n>>d;
        ll cha=0;
        for(ll i=1; i<=n; i++){
            cin>>x[i];
        }
        cha=x[2]-x[1];
        if(d>=(cha*2)){
            int nd=(d/cha)*2;
            if(n>=nd) cout<<n-nd+1<<endl;
            else cout<<0<<endl;
        }else{
            cout<<0<<endl;
        }
	}
	return 0;
}
