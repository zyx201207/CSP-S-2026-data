#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500010];
vector<ll> e[500010];

int check(int u){
	int sum=1;
	for(ll i=u-1;i>=1;i--){
		if(m>=(a[u]-a[i])){
			m=m-(a[u]-a[i]);
			sum++;
		}
		else break;
	}
	return sum;
}

void erfen(){
	ll l=1,r=n;
	ll cnt=1;
	while(l<=r){
		ll k,mid=(l+r)/2;
		ll f=mid;
		while(mid+1<=n){
			if(a[mid]==a[mid+1]) mid++;
			else break;
		}
		k=check(mid);
		if(k>cnt){
			cnt=k;
			r=f-1;	
		}
		else l=f+1;
	}
	printf("%lld",cnt);
}



int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	erfen();
	
	return 0;
} 
