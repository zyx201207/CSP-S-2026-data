#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,ans;
ll x[500001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
		ll s;
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			ans=0;
			for(int j=1;j<=n;j++){
				cin>>x[j];
			}
			s=x[2]-x[1];
			if(d<2*s) ans=0;
			else{
				ans=n+1;
				for(;;){
					if(d>=s){
						d-=s;
						ans-=2;
					}
					if(d<s){
						break;
					}
				}
			}
			if(ans<0) cout<<0<<endl;
			else cout<<ans<<endl;
		}
	return 0;
}
