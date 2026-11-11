#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
int c,t,n,d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flagA=1;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
//		if(c>=11&&c<=12){
			ll ans=0;
			ll step=d/(a[2]-a[1]);
			if(step+1>=n){
				cout<<0<<endl;
			}
			else {
				for(ll i=1;i<=n-step;i++){
					for(ll j=1;j<step;j++){
						if(i+step+j<=n) ans++;
					}
				}
				cout<<ans<<endl;
			}
			
//		}
	}
	return 0;
} 
