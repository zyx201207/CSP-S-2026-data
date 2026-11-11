#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500001];
ll f[500001];
ll ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1;
		ll r=i;
		while(l+1<r){
			ll mi=(l+r)/2;
			if(a[i]*(i-mi+1ll)>=m+(f[i]-f[mi-1ll]))
				l=mi;
			else
				r=mi;
		}
		if(a[i]*(i-l+1ll)>m+(f[i]-f[l-1ll]))
			l++;
		ans=max(ans,i-l+1ll);
	}
	printf("%lld",ans);
	return 0;
}
