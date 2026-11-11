#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	while(t--){
		bool d=0;
		ll i=0,j=0;
		for(i=1;i<=n;i++){
			a[i]=0;
		}
		ll m;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				d=1;
			}
		}
		if(d==0){
			ll c=0,c1=0;
			for(i=1;i<=n;i++){
				if(a[i]-a[0]>m)break;
			}
			j=i;
			for(i=1;i+j<=n;i+=j){
				c++;
			}
			c1=n-i;
			ll c2=c+c1;
			ll sum;
			for(i=c2;i>c;i--){
				sum*=i;
			}
			for(i=c1;i>0;i--){
				sum/=i;
			}
			cout<<sum;
		}
	}
	return 0;
}

