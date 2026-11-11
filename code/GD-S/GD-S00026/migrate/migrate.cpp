#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;
ll c,t,x[2000005];
ll ans=0,l=1,m1=0,m2=0;
bool flag=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(ll i=1;i<=t;++i){ 
		flag=0;
		ans=0;
		l=1;
		m1=0;
		m2=0;
		ll n,d;
		cin>>n>>d;
		for(ll j=1;j<=n;++j){
			cin>>x[j];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		for(ll j=1;j+3<=n;++j){
			if(x[j+1]-x[j]<=d){
				if(x[j+2]-x[j]<=d){
					if(x[j+3]-x[j+1]<=d&&x[j+3]-x[j]>d){
						if(flag==1){
							ans+=(j+3-m2)*(m1-l+1);
							l=m2-2;
							m1=j;
							m2=j+3;
						}else{
							m1=j;
							m2=j+3;
							flag=1;
						}
					}else{
						
					}
				}else{
					
				}
			}else{
				l=j+1;
			}
		}
		if(flag==1){
			ans+=(n-m2+1)*(m1-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

