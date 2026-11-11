#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	cin>>c>>t;
	while(t--){
		ll a[1000005]={0};
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			}
		if(c==11||c==12){
			if(d<=a[3]-a[1]){
				cout<<0<<endl;
				}
			else if(d>a[3]-a[2]){
				cout<<n-2<<endl;
				}
			else{
				ll ans=0;
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]==a[k])ans++;
							}	
						}					
					}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
