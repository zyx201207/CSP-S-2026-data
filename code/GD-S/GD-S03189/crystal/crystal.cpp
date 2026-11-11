#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll a[500005];
ll cz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cz[i]=a[i]-a[i-1];
	}
	ll ans=0;
	ll len=1;
	ll res=m;
	ll l=1,r=1;
	while(r<=n){
		r++;
		if(res>=len*cz[r]){
			res-=len*cz[r];
			len++;
		}
		else{
			while(res<len*cz[r]){
				ll c=a[r-1]-a[l];
				res+=c;
				l++;
				len--;
			}
			res-=len*cz[r];
			len++;
		}
		ans=max(ans,len);
		if(r==n) break;
	}
	printf("%lld\n",ans);
	return 0;
} 
