#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005],fx[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll flag=0;
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		fx[1]=x[1];
		ll xy=x[2]-x[1];
		for(int i=2;i<=n;i++){
			fx[i]=x[i]-x[i-1];
			if(fx[i]!=xy){
				flag=1;
			}
		}
		if(!flag){
			if(d>=2*xy){
				ll qwq=(x[n]-x[1])/(x[2]-x[1]);
				cout<<qwq-2<<endl;				
			}if(d<2*xy){
				cout<<"0"<<endl;				
			}		
		}else{
			cout<<"0"<<endl;
		}
	}

	return 0;
}

