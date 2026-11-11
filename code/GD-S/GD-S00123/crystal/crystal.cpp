#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lpx 500005
ll n,m,a[lpx],ans=0,qian[lpx],l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	l=n;
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)qian[i]=qian[i-1]+a[i];
	for(ll i=n;i>=1;i--){
		ll cnt=1;
		while(a[i]==a[i-1]){
			i--;
			cnt++;
		}
		ans=max(ans,cnt);
		l=i-1;
		while(l>=1&&qian[i]-qian[l-1]+m>=a[i]*(i-l+1)){
			ans=max(ans,cnt+i-l);
			l--;
		}
	}
	printf("%lld",ans);
	return 0;
} 
