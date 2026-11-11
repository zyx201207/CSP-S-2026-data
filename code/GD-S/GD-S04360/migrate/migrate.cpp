#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
ll n,d;
ll a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ll sum=0;
		for(ll i=1,j=4;j<=n;i++,j++){
			ll d1=i,d2z=0,d2y=0,d3=0,d4=0,cis1=0;
			for(ll j=d1+1;j<=n;j++){
				if(abs(a[d1]-a[j])<=d){
					if(!d2z) d2z=j;
					else d2y=j;
					cis1++;
				}
				else break;
			}
			if(cis1==2)
			for(ll j=d2y+1;j<=n;j++){
				if(abs(a[d2y]-a[j])<=d){
					d3=j;
					if(cis1==2)
					if(a[d2z]-a[d1]<=d&&a[d2y]-a[d1]<=d&&a[d3]-a[d2z]<=d&&a[d3]-a[d2y]<=d&&a[d3]-a[d1]>d)
					sum++;
				}
				else break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
