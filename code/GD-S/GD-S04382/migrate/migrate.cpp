#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,pdk,ans,g;
ll x[2222222],b[2222222];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		if(n<4||d==1){
			cout<<0<<"\n";
			continue;
		}
		x[n+1]=1e18;
		for(ll i=4;i<=n;i++){
			if((x[i-2]-x[i-3]<=d)&&(x[i-1]-x[i-3]<=d)&&(x[i]-x[i-3]>d)&&(x[i]-x[i-2]<=d)&&(x[i]-x[i-1]<=d)){
				//1能到2,3不到4,2能到4,3能到4 
				ans++;				
			}
		}
		cout<<ans<<"\n";
	}
}
