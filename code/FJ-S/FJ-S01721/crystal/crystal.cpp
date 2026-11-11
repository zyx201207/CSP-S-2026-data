#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
ll n, m;
ll a[N];
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll cost=0,l=1,r=1,ans=0;
	sort(a+1,a+1+n);
	while(r<=n){
		r++;
		if(r>n) break;
		cost+=(a[r]-a[r-1])*(r-l);
		while(cost>m){
			cost-=(a[r]-a[l]);
			l++;
			if(l>r) break;
		}
		if(l>r){
			r=l;
			cost=0;
			continue;
		}
//		cout<<l<<' '<<r<<' '<<cost<<endl;
		ans=max(r-l+1,ans);
	}
	printf("%lld",ans);
	return 0;
}

