#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll a[2000005];
ll s[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,d;
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>=2){
				s[i]=a[i]-a[i-1];
			}
		}
		ll len=n;
		for(ll i=1;i<=n;i++){
			if(d<s[i]){
				len=i-1;
				break;
			}
		}
		ll cnt=0;
		for(ll i=1;i<=len;i++){
			for(ll j=i+2;j<=len;j++){
				if(a[j]-a[i]<=d||j-i==2)	continue;
				else{
					if(j-i+1==4){
						cnt++;
					}
					else{
						ll sum=0;
						ll k=(i+j)/2;
						for(ll len=i+1;len<=k+1;len++){
							if(a[len]-a[i]<=d&&a[j]-a[len]<=d){
								sum++;
							}
						}
						if(sum==2){
							cnt++;
						}
					} 
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
