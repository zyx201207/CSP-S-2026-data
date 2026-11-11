#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,pt[2000009],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>pt[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if((pt[j]-pt[i])>d&&(pt[j]-pt[i])<(2*d)&&j-i==3){
					ans++;
//					cout<<i<<" "<<j<<endl;
				}
		}
		}
		cout<<ans<<endl;
		ans=0;
	}
return 0;
} 
