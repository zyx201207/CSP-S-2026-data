#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
const int N=5e5+3;
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll l=n-1;
	while(m){
		if(l==0)break;
		int la=a[n]-a[l];
		if(m>=la)l--,m-=la;
		else break;
	}
	ans=n-l;
	for(int i=n-1;i>=1;i--){
		m=m+(a[i+1]-a[i])*(i-l);
		while(m){
			if(l==0)break;
			ll la=a[i]-a[l];
			if(m>=la)l--,m-=la;
			else break;
		}
		ans=max(ans,i-l);
	}
	printf("%lld",ans);
	return 0;
}
