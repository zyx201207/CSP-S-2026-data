#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll cry[500005];
ll suc[500005];

bool check(ll x){
	ll tip=cry[x];
	ll tot=x*tip;
	if(suc[x]+m>=tot){
		return true;
	}
	else{
		return false;
	}

}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&cry[i]);
	}
	
	
	sort(cry+1,cry+n+1);
	
	for(ll i=1;i<=n;i++){
		suc[i]=suc[i-1]+cry[i];
	}
	

	bool key=true;
	bool tey=true;
	ll p=0;

	for(ll i=2;i<=n;i++){
		p=cry[3]-cry[2];
		if(cry[i]!=cry[i-1]+p){
			tey=false;
			break;
		}
	}
	
	for(ll i=1;i<=n;i++){
		if(cry[i]!=i){
			key=false;
			break;
		}
	}
	
	if(key){
		ll l=1,r=n;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ll ans=l;
		printf("%lld\n",ans);
		
		return 0;
	}
	
	if(tey){
		ll l=1,r=n;
		while(l<r){
			ll mid=(l+r+1)/2;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ll ans=l;
		printf("%lld\n",ans);
		
		return 0;
	}

	ll ans=0;

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n-i+1;j++){
			ll tip=cry[j+i-1];
			ll tot=i*tip;
	
			if(suc[j+i-1]-suc[j-1]+m>=tot){
				ans=i;
			}
			else{
				continue;
			}
			
		}
	}

	printf("%lld\n",ans);
	
	return 0;
}
