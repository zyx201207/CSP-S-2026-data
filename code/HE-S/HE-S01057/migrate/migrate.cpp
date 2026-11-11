#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,x[10000001],m,sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ll k=x[2]-x[1];
		ll a=m/k;
		if(a<0) a=a*-1;
		if(a<=1 || a>=n){
			cout<<0<<endl;
		}else{
			ll f;
			if(m%k==0) f=m/k-1;
			else f=m/k;
			sum=sum+(n-a-f-1)*f+(f-1)*f/2+1;
			cout<<sum<<endl;
		}
	}
	
	return 0;
}

