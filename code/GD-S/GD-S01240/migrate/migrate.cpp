#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;++i){
		cin>>n>>d;
		for(ll j=1;j<=n;++j){
			cin>>x[j];
		}
		ll sum=0,ans=1000001;
		for(ll j=1;j<=n;++j){
			sum=0;
			for(ll k=1;k<=n;++k){
				sum+=x[k]-x[j];
				if(sum<=d){
					ans=min(sum,ans);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
