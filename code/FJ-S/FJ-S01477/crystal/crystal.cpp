#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll l,r,mid;
bool cheak(ll x){
	//printf("\n%lld\n",x);
	ll sum=0;
	for(int i=1;i<=x;i++) sum+=a[x]-a[i];
	//printf("%lld ",sum);
	if(sum<=m) return true;
	for(int i=x+1;i<=n;i++){
		sum+=a[i-x]-a[i-1]+(a[i]-a[i-1])*(x-1);
		//printf("%lld ",sum);
		if(sum<=m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)>>1;
		if(cheak(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%lld\n",l);
	return 0;
}
//2026.10.31 15:37
