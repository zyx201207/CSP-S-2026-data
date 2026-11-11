#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
ll n,m,find,out=-9999,a[N];

ll check(ll x){
	ll cnt=0,ans=0;
	for(ll i=1;i<=n;i++){
		if(a[i]<=x){
			cnt=cnt+x-a[i];
			ans++;
			if(cnt>m) return ans;
		}
		else{
			return ans;
		}
	}
}

int main(){
	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n+m;i++){
		if(check(i)>=out){
			out=check(i);
		}
		else{
			break;
		}
	}
	cout<<out;
	
	return 0;
} 
